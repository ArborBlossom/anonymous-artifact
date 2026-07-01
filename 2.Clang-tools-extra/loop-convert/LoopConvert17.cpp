// loop-convert17.cpp       2025.09.08 指针保留版
/*================================ 头文件说明 ================================*/
#include "llvm/ADT/APInt.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/Error.h"
#include <llvm/Support/Path.h>
#include "llvm/Support/Casting.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "clang/AST/AST.h"
#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Frontend/ASTUnit.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Parse/ParseAST.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/Refactoring.h"
#include "clang/Tooling/Core/Replacement.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Lex/Lexer.h"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include "clang/Tooling/ArgumentsAdjusters.h"
#include "nlohmann/json.hpp"

/*=============================== 命名空间声明 ===============================*/
using namespace std;
using namespace llvm;
using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;
using json = nlohmann::json;

/*============================= 全局配置数据结构 =============================*/
json result_json;
json chromosome_json;

/*======================= AST访问器（核心转换逻辑实现） =======================*/
class MyVariableASTVisitor : public RecursiveASTVisitor<MyVariableASTVisitor> {
public:
    MyVariableASTVisitor(ASTContext &Ctx, Rewriter &R)
        : Context(Ctx), TheRewriter(R) {}

    bool VisitVarDecl(VarDecl *Variable) {
        SourceManager &SM = Context.getSourceManager();
        if (!SM.isInMainFile(Variable->getLocation())) return true;
        
        // 跳过函数参数（在VisitFunctionDecl中处理）
        if (isa<ParmVarDecl>(Variable)) return true;
        
        replaceVariable(Variable);
        return true;
    }

    bool VisitCallExpr(CallExpr *Call) {
        if (FunctionDecl *FuncDecl = Call->getDirectCallee()) {
            processFunctionCall(Call, FuncDecl);
        }
        return true;
    }

    bool VisitFunctionDecl(FunctionDecl *Func) {
        SourceManager &SM = Context.getSourceManager();
        if (!SM.isInMainFile(Func->getLocation())) return true;
        
        userFunctions.insert(Func->getNameAsString());
        replaceFunctionSignature(Func);
        return true;
    }

private:
    ASTContext &Context;
    Rewriter &TheRewriter;
    unordered_set<string> userFunctions;

    // 统一处理所有变量类型 - 关键修复点
    void replaceVariable(VarDecl *Variable) {
        std::string VarName = Variable->getNameAsString();
        if (!chromosome_json.contains(VarName)) return;

        // // 输出变量名和类型
        // llvm::errs() << "处理变量: " << VarName 
        //              << ", 类型: " << Variable->getType().getAsString() << "\n";
        
        if (TypeSourceInfo *TInfo = Variable->getTypeSourceInfo()) {
            TypeLoc TL = TInfo->getTypeLoc();
            
            // 关键修复：记录指针位置并替换基础类型
            replaceBaseTypeWithPointers(TL, chromosome_json[VarName]);
        }
    }

    void processFunctionCall(CallExpr *Call, FunctionDecl *FD) {
        std::string FuncName = FD->getNameAsString();
        if (!chromosome_json.contains(FuncName)) return;
        if (chromosome_json[FuncName] != 1) return;

        SourceManager &SM = Context.getSourceManager();
        if (SM.isInSystemHeader(FD->getLocation())) {
            SourceRange NameRange = Call->getCallee()->getSourceRange();
            TheRewriter.ReplaceText(NameRange, FuncName + "f");
        }
    }

// 函数参数类型处理（修复版）
void replaceParamType(ParmVarDecl *Param) {
    std::string ParamName = Param->getNameAsString();
    
    // 使用参数名查找配置
    if (!chromosome_json.contains(ParamName)) {
        return; // 没有参数配置，跳过处理
    }
    
    int precision = chromosome_json[ParamName];
    
    if (TypeSourceInfo *TInfo = Param->getTypeSourceInfo()) {
        TypeLoc TL = TInfo->getTypeLoc();
        
        // 关键修复：使用统一的指针处理函数
        replaceBaseTypeWithPointers(TL, precision);
    }
}

// 函数签名统一处理（修复版）
void replaceFunctionSignature(FunctionDecl *Func) {
    std::string FuncName = Func->getNameAsString();
    bool hasFuncConfig = chromosome_json.contains(FuncName);
    
    // 处理返回值类型（仅在函数名有配置时）
    if (hasFuncConfig) {
        int precision = chromosome_json[FuncName];
        
        if (TypeSourceInfo *TSI = Func->getTypeSourceInfo()) {
            if (FunctionTypeLoc FTL = TSI->getTypeLoc().getAs<FunctionTypeLoc>()) {
                TypeLoc ReturnTL = FTL.getReturnLoc();
                
                // 递归处理返回类型
                while (!ReturnTL.isNull()) {
                    if (PointerTypeLoc PTL = ReturnTL.getAs<PointerTypeLoc>()) {
                        // 记录指针位置但不修改
                        ReturnTL = PTL.getPointeeLoc();
                    } else if (ArrayTypeLoc ATL = ReturnTL.getAs<ArrayTypeLoc>()) {
                        ReturnTL = ATL.getElementLoc();
                    } else if (BuiltinTypeLoc BTL = ReturnTL.getAs<BuiltinTypeLoc>()) {
                        SourceLocation Start = BTL.getBeginLoc();
                        SourceLocation End = Lexer::getLocForEndOfToken(
                            BTL.getEndLoc(), 0, Context.getSourceManager(), Context.getLangOpts());
                        
                        std::string NewType = (precision == 1) ? "float" : "double";
                        TheRewriter.ReplaceText(SourceRange(Start, End), NewType);
                        break;
                    } else {
                        ReturnTL = ReturnTL.getNextTypeLoc();
                    }
                }
            }
        }
    }

    // 总是处理参数类型（即使函数名没有配置）
    for (ParmVarDecl *Param : Func->parameters()) {
        replaceParamType(Param);
    }
}

// 关键修复：记录指针位置并替换基础类型
    void replaceBaseTypeWithPointers(TypeLoc TL, int precision) {
        // 收集所有指针位置
        vector<SourceLocation> starLocations;
        TypeLoc baseTypeLoc;
        
        // 递归遍历类型链，收集指针位置
        while (!TL.isNull()) {
            if (PointerTypeLoc PTL = TL.getAs<PointerTypeLoc>()) {
                // 记录指针位置
                starLocations.push_back(PTL.getStarLoc());
                TL = PTL.getPointeeLoc();
            } else if (ArrayTypeLoc ATL = TL.getAs<ArrayTypeLoc>()) {
                // 处理数组类型
                TL = ATL.getElementLoc();
            } else if (BuiltinTypeLoc BTL = TL.getAs<BuiltinTypeLoc>()) {
                // 找到基础类型位置
                baseTypeLoc = BTL;
                break;
            } else if (ElaboratedTypeLoc ETL = TL.getAs<ElaboratedTypeLoc>()) {
                // 处理详细类型
                TL = ETL.getNamedTypeLoc();
            } else {
                TL = TL.getNextTypeLoc();
            }
        }
        
        // 如果找到基础类型，进行替换
        if (baseTypeLoc && baseTypeLoc.getAs<BuiltinTypeLoc>()) {
            BuiltinTypeLoc BTL = baseTypeLoc.getAs<BuiltinTypeLoc>();
            
            // 计算基础类型的范围
            SourceLocation Start = BTL.getBeginLoc();
            SourceLocation End = BTL.getEndLoc();
            
            // // 获取替换前的文本
            // StringRef OldText = Lexer::getSourceText(
            //     CharSourceRange::getTokenRange(SourceRange(Start, End)),
            //     Context.getSourceManager(), Context.getLangOpts());
            
            // 确定新类型
            std::string NewType = (precision == 1) ? "float" : "double";
            // llvm::errs() << "  替换基础类型: \"" << OldText.str() 
            //              << "\" -> \"" << NewType << "\"\n";
            
            // 替换基础类型
            TheRewriter.ReplaceText(SourceRange(Start, End), NewType);
            
            // // 确保指针修饰符被保留
            // if (!starLocations.empty()) {
            //     llvm::errs() << "  保留 " << starLocations.size() << " 个指针修饰符\n";
            // }
        }
    }
};

/*============================= AST消费者（调度器） ============================*/
class MyASTConsumer : public ASTConsumer {
public:
    MyASTConsumer(ASTContext &Ctx, Rewriter &R) : Visitor(Ctx, R) {}

    bool HandleTopLevelDecl(DeclGroupRef DR) override {
        for (Decl *D : DR) {
            Visitor.TraverseDecl(D);
        }
        return true;
    }

private:
    MyVariableASTVisitor Visitor;
};

/*============================ 前端动作（工程入口） ============================*/
class MyFrontendAction : public ASTFrontendAction {
public:
    void EndSourceFileAction() override {
        SourceManager &SM = TheRewriter.getSourceMgr();
        TheRewriter.getEditBuffer(SM.getMainFileID()).write(llvm::outs());
    }
    
    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef) override {
        TheRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
        return std::make_unique<MyASTConsumer>(CI.getASTContext(), TheRewriter);
    }

private:
    Rewriter TheRewriter;
};

/*================================ 配置加载 ================================*/
static llvm::cl::OptionCategory ToolingCategory("my-tool options");
static llvm::cl::opt<std::string> ChromosomeNum("chromosome", 
    llvm::cl::desc("Specify chromosome number"), 
    llvm::cl::Required, 
    llvm::cl::cat(ToolingCategory));

/*================================ 主程序入口 ================================*/
int main(int argc, const char **argv) {
    // 加载JSON配置文件
    std::ifstream i("/root/mytool2/src/ConfigMerged.json");
    i >> result_json;
    i.close();

    auto ExpectedParser = CommonOptionsParser::create(argc, argv, ToolingCategory);
    if (!ExpectedParser) {
        llvm::errs() << "Error creating options parser\n";
        return 1;
    }
    
    chromosome_json = result_json["chromosome" + ChromosomeNum.getValue()];

    ClangTool Tool(ExpectedParser->getCompilations(), 
                  ExpectedParser->getSourcePathList());

    // 添加必要的编译参数
    std::vector<std::string> ExtraArgs;
    ExtraArgs.push_back("-std=c++17");
    ExtraArgs.push_back("-I/usr/include");
    ExtraArgs.push_back("-I/usr/local/include");
    
    Tool.appendArgumentsAdjuster(getInsertArgumentAdjuster(
        ExtraArgs, ArgumentInsertPosition::BEGIN));

    return Tool.run(newFrontendActionFactory<MyFrontendAction>().get());
}
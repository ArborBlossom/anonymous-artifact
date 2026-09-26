#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double T_hot = 800.0; // 高温热源温度 K
    double T_cold = 300.0; // 低温热源温度 K
    double Q_in = 1000.0;  // 输入热量 J
    double Q_out = Q_in * T_cold / T_hot; // 输出热量 J
    double W = Q_in - Q_out; // 做功 J
    double eta = W / Q_in; // 效率
    cout << "卡诺循环效率: " << std::scientific << std::setprecision(16) << eta << endl;
    return 0;
}
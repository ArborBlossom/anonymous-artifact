#include <iostream>
#include <iomanip>
using namespace std;

double cx;
double cy;
double all;

// 计算三角形质心坐标
void centroid(double x1,double y1,double x2,double y2,double x3,double y3){
    cx = (x1 + x2 + x3) / 3.0;
    cy = (y1 + y2 + y3) / 3.0;
    all = cx + cy;
}

int main(){
    centroid(0.0, 0.0,           // P1: (0,0) deepseek拟定输入
             1.321321123456789, 0.0,  // P2: (1.000000123456789, 0)
             0.0, 2.789789987654321  // P3: (0, 2.000000987654321);
    );
    cout << "Centroid: " << std::scientific << std::setprecision(16) << all << endl;
    return 0;
}
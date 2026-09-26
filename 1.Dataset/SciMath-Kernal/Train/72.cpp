#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 1.2;     // kg
    double delta_T = 30.0; // 摄氏度
    double q = 150.0;   // 热量 kJ
    double c = q / (m * delta_T);
    cout << "比热容 c = " << std::scientific << std::setprecision(16) << c << endl;
    return 0;
}
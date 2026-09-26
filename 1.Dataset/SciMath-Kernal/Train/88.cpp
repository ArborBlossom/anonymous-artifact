#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double area = 10.0;         // 面积 m²
    double irradiance = 5.0;    // 日照强度 kWh/m²/天
    double efficiency = 0.18;   // 光电转换效率
    double days = 365.0;        // 天数
    double energy = area * irradiance * efficiency * days;
    cout << "年发电量：" << std::scientific << std::setprecision(16) << energy << endl;
    return 0;
}
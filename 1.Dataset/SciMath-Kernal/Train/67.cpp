#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double T = 30.0; // 当前温度 °C
    double Td = 24.0; // 露点温度 °C
    double RH = 100 * (exp((17.625 * Td)/(243.04 + Td)) / exp((17.625 * T)/(243.04 + T)));
    cout << "相对湿度 RH = " << std::scientific << std::setprecision(16) << RH << endl;
    return 0;
}
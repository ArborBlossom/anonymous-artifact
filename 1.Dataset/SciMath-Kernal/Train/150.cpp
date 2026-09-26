#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k = 100.0;   // 弹簧系数 N/m
    double x = 0.2;     // 伸长量 m
    double SPE = 0.5 * k * x * x;
    cout << "弹簧势能: " << std::scientific << std::setprecision(16) << SPE << endl;
    return 0;
}
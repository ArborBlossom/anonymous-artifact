#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double power = 60.0; // W
    double hours = 5.0;  // 每天使用小时
    double days = 30.0;
    double energy = (power * hours * days) / 1000.0; // kWh
    cout << "月耗电量：" << std::scientific << std::setprecision(16) << energy << endl;
    return 0;
}
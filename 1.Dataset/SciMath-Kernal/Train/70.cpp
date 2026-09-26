#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double Voc = 21.0;  // 开路电压 V
    double Isc = 5.0;   // 短路电流 A
    double Vmp = 17.0;  // 最大功率电压
    double Imp = 4.5;   // 最大功率电流
    double Pmp = Vmp * Imp;
    cout << "最大功率点：" << std::scientific << std::setprecision(16) << Pmp << endl;
    return 0;
}
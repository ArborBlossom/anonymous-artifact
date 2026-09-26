#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double capacity_mAh = 2200.0; // 电池容量
    double current_mA = 500.0;     // 放电电流
    double time_h = 2.0;           // 时间小时
    double discharged = current_mA * time_h;
    double soc = 100.0 * (capacity_mAh - discharged) / capacity_mAh;
    cout << "当前剩余电量：" << std::scientific << std::setprecision(16) << soc << endl;
    return 0;
}
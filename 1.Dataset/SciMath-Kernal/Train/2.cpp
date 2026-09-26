#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double m = 5.57;    // 质量 kg
    double v = 12.36;   // 速度 m/s
    double h = 10.9;   // 高度 m
    const double g = 9.8;
    double pe = m * g * h;         // 势能
    cout << "Potential Energy: " << std::scientific << std::setprecision(16) << pe << " J\n";
    return 0;
}
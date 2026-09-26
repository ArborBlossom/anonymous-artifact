#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double m = 5.57;    // 质量 kg
    double v = 12.36;   // 速度 m/s
    double h = 10.9;   // 高度 m
    const double g = 9.8;
    double ke = 0.5 * m * v * v;  // 动能
    cout << "Kinetic Energy: " << std::scientific << std::setprecision(16) << ke << " J\n";
    return 0;
}
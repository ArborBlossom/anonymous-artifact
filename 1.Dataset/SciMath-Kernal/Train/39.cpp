#include <iostream>
#include <iomanip> //
using namespace std;

int main() {
    const double G = 6.67430e-11;  // 万有引力常数
    double m1 = 5.972e24;          // 地球质量 kg
    double m2 = 7.348e22;          // 月球质量 kg
    double r  = 3.84e8;            // 它们中心距离 m
    double F  = G * m1 * m2 / (r * r);
    cout << "Gravitational Force: " << std::scientific << std::setprecision(16) << F << " N\n" << endl;
    return 0;
}

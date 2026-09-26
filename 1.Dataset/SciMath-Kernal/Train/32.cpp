#include <iostream>
#include <cmath>
using namespace std;

double attenuation(double alpha1, double L1) {
    return exp(-alpha1 * L1);
}

int main() {
    double alpha = 0.2;   // 衰减系数 dB/km
    double L = 10.0;      // 长度 km
    attenuation(alpha, L);
    cout << "Transmission factor: " << std::scientific << std::setprecision(16) << attenuation(alpha, L) << endl;
    return 0;
}
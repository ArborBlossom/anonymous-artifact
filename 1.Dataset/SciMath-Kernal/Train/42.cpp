#include <iostream>
#include <iomanip> //
using namespace std;

int main() {
    double m = 0.5;    // 质量 kg
    double c = 4.2e3;  // 水的比热 J/(kg·K)
    double dT = 10.0;  // 温升 K
    double Q = m * c * dT;
    cout << "Heat Energy: " << std::scientific << std::setprecision(16) << Q << " J\n" << endl;
    return 0;
}
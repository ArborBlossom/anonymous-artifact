#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double p = 0.1;       // 声压 Pa
    double p0 = 2e-5;     // 参考声压 Pa
    double L = 20 * log10(p / p0); // 声压级 dB
    cout << "声压级: " << std::scientific << std::setprecision(16) << L << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double c = 343.0;  // 声速 m/s
    double L = 0.5;    // 管长 m
    int n = 1;         // 基频
    double f = (double)n * c / (2 * L);
    cout << "基频驻波 f = " << std::scientific << std::setprecision(16) << f << endl;
    return 0;
}
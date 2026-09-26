#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 10.0;   // kg
    double r = 0.2;    // m
    double I = 0.5 * m * r * r;
    cout << "实心圆柱惯性 I = " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}
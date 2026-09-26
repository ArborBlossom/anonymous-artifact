#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double R1 = 100.0;
    double R2 = 200.0;
    double R3 = 300.0;
    double R_eq = 1.0 / (1.0/R1 + 1.0/R2 + 1.0/R3);
    cout << "等效电阻 = " << std::scientific << std::setprecision(16) << R_eq << endl;
    return 0;
}
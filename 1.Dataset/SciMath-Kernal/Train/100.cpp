#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double I = 100.0; // 光强 cd
    double d = 2.0;   // 距离 m
    double E = I / (d * d);
    cout << "照度 E = " << std::scientific << std::setprecision(16) << E << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double linearInterpolate(double x00, double y00, double x11, double y11, double xx) {
    return y00 + ((y11 - y00) / (x11 - x00)) * (xx - x00);
}

int main() {
    double x0 = 1.0;
    double y0 = 2.0;
    double x1 = 3.0;
    double y1 = 6.0;
    double x = 2.0;
    double y = linearInterpolate(x0, y0, x1, y1, x);
    cout << "线性插值结果 y = " << std::scientific << std::setprecision(16) << y << endl;
    return 0;
}
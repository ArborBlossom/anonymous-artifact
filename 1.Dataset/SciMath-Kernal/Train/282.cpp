#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double ellipseCircumference(double a, double b) {
    double h = pow((a-b)/(a+b),2);
    return M_PI*(a+b)*(1 + (3*h)/(10 + sqrt(4 - 3*h)));
}

int main() {
    double aa = 5.0;
    double bb = 3.0;
    double C = ellipseCircumference(aa,bb);
    cout << "Ellipse circumference ≈ " << std::scientific << std::setprecision(16) << C << endl;
    return 0;
}
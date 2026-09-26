#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double ellipsePerim(double a, double b) {
    if (a <= 0 || b <= 0) return 0.0;
    double h = pow((a-b)/(a+b), 2);
    return M_PI*(a+b)*(1 + (3*h)/(10 + sqrt(4-3*h)));
}

int main() {
    double axes[][2] = {{5.0,3.0},{10.0,4.0},{7.5,2.5}};
    double p = ellipsePerim(axes[0][0], axes[0][1]);
    cout << "Perim ≈ " << std::scientific << std::setprecision(16) << p << endl;
    return 0;
}
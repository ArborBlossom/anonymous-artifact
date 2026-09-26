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
    double p = ellipsePerim(axes[1][0], axes[1][1]);
    cout << "Perim ≈ " << std::scientific << std::setprecision(16) << p << endl;
    return 0;
}
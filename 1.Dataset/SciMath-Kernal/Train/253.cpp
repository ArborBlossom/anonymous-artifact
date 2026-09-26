#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

const double x4[4] = {-0.861136, -0.339981, 0.339981, 0.861136};
const double w4[4] = {0.347855, 0.652145, 0.652145, 0.347855};

double f(double x) { return 1.0/(1.0+x*x); }

double gaussQuad4(double a, double b) {
    double mid = 0.5*(a+b);
    double half = 0.5*(b-a);
    double sum = 0.0;
    for (int i = 0; i < 4; i++)
        sum += w4[i] * f(mid + half * x4[i]);
    return half * sum;
}

int main() {
    gaussQuad4(0.0,1.0);
    cout << "4-point Gauss-Legendre ≈ " << std::scientific << std::setprecision(16) << gaussQuad4(0.0,1.0) << endl;
    return 0;
}
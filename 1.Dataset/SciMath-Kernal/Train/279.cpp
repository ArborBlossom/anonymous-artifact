#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void eigen2(double M[2][2], double *lambda) {
    double a = 1.0;
    double b = - (M[0][0] + M[1][1]);
    double c = M[0][0]*M[1][1] - M[0][1]*M[1][0];
    double disc = b*b - 4*a*c;
    *lambda = (-b + sqrt(disc)) / 2.0;
}

int main() {
    double M[2][2] = {{4.0, 2.0}, {1.0, 3.0}};
    double lambda;
    eigen2(M, &lambda);
    cout << "Eigenvalues = " << std::scientific << std::setprecision(16) << lambda << endl;
    return 0;
}
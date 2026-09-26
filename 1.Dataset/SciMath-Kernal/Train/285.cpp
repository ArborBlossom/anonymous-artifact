#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double ellipticK(double m, int n) {
    double a=1.0;
    double b=sqrt(1.0-m);
    double c;
    double sum=0.0;
    for (int i=0; i<n; i++) {
        c = (a - b) / 2.0;
        a = (a + b) / 2.0;
        b = sqrt(a*b);
        sum += pow(2.0, i) * c * c;
    }
    return M_PI/(2.0*a);
}

int main() {
    double mm = 0.5;
    ellipticK(mm, 10);
    cout << "K(m) ≈ " << std::scientific << std::setprecision(16) << ellipticK(mm, 10) << endl;
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double erfSimpson(double x, int n) {
    double h = x / n;
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double t = i*h;
        double coeff = (i==0||i==n)?1.0:(i%2==0?2.0:4.0);
        sum += coeff * exp(-t*t);
    }
    return (2.0/sqrt(M_PI)) * sum * h / 3.0;
}

int main() {
    double x = 1.0;
    erfSimpson(x,1000);
    cout << "erf(x) ≈ " << std::scientific << std::setprecision(16) << erfSimpson(x,1000) << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double altHarmonicLn2(int terms) {
    double sum = 0.0;
    for (int i = 1; i <= terms; i++) {
        double term = (i % 2 == 0 ? -1.0 : 1.0) / i;
        sum += term;
    }
    return sum;
}

int main() {
    int n = 1000000;
    double approx = altHarmonicLn2(n);
    cout << "Alternating harmonic ≈ " << std::scientific << std::setprecision(16) << approx << endl;
    return 0;
}
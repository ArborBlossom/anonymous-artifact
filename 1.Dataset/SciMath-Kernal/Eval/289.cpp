#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double nilakanthaPi(int terms) {
    double pi = 3.0;
    int sign = 1;
    for (int i = 2; i < 2*terms+2; i += 2) {
        double term = 4.0 / (i*(i+1)*(i+2));
        pi += sign * term;
        sign = -sign;
    }
    return pi;
}

int main() {
    double pi0 = nilakanthaPi(100000);
    cout << "Nilakantha π ≈ " << std::scientific << std::setprecision(16) << pi0 << endl;
    return 0;
}
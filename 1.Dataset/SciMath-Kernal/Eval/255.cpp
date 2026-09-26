#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double taylorArctan(double x, int terms) {
    double sum = 0.0;
    double term;
    for (int n = 0; n < terms; n++) {
        term = (n % 2 == 0 ? 1.0 : -1.0) * 
               pow(x, 2*n + 1) / (2*n + 1);
        sum += term;
    }
    return sum;
}

int main() {
    double x0 = 0.5;      // |x| ≤ 1
    int terms = 1000;
    double approx = taylorArctan(x0, terms);
    cout << "arctan(x) ≈ " << std::scientific << std::setprecision(16) << approx << endl;
    return 0;
}
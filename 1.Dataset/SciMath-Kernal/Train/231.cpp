#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lagrange(double x[], double y[], int n, double xi1) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) term *= (xi1 - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    double x[4] = {0, 1, 2, 3};
    double y[4] = {1, 3, 2, 5};
    double xi = 2.5;
    double yi = lagrange(x, y, 4, xi);
    cout << "Interpolated at xi: " << std::scientific << std::setprecision(16) << yi << endl;
    return 0;
}
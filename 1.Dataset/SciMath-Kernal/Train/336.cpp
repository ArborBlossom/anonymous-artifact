#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lagrange(double X[], double Y[], int n, double x) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = Y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (x - X[j]) / (X[i] - X[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    double X[] = {0.0, 1.0, 2.0, 4.0};
    double Y[] = {1.0, 3.0, 2.0, 5.0};
    int n = sizeof(X)/sizeof(X[0]);
    double xi[] = {1.5, 3.0};
    lagrange(X, Y, n, xi[1]);
    cout << "P(xi[1]) = " << std::scientific << std::setprecision(16) << lagrange(X, Y, n, xi[1]) << endl;
    return 0;
}
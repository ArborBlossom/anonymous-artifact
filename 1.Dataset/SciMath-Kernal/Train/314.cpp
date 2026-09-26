#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double vandermondeDet(double x[], int n) {
    double det = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            det *= (x[j] - x[i]);
    return det;
}

int main() {
    double x[] = {1.0, 2.0, 4.0, 7.0};
    int n = sizeof(x)/sizeof(x[0]);
    double det0 = vandermondeDet(x, n);
    cout << "Vandermonde Determinant = " << std::scientific << std::setprecision(16) << det0 << endl;
    return 0;
}
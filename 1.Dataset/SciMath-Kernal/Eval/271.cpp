#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double meanSquareError(double actual[], double predicted[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = actual[i] - predicted[i];
        sum += diff * diff;
    }
    return sum / n;
}

int main() {
    double actual[] = {1.0, 2.0, 3.0, 4.0};
    double predicted[] = {0.9, 2.1, 2.9, 4.2};
    int n = sizeof(actual)/sizeof(actual[0]);
    double mse = meanSquareError(actual, predicted, n);
    cout << "MSE = " << std::scientific << std::setprecision(16) << mse << endl;
    return 0;
}
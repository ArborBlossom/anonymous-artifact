#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double meanAbsoluteError(double pred[], double actual[], int n) {
    double error = 0;
    for (int i = 0; i < n; i++)
        error += fabs(pred[i] - actual[i]);
    return error / n;
}

int main() {
    double pred[] = {3.0, -0.5, 2.0, 7.0};
    double actual[] = {2.5, 0.0, 2.0, 8.0};
    int n = sizeof(pred) / sizeof(pred[0]);
    meanAbsoluteError(pred, actual, n);
    cout << "MAE = " << std::scientific << std::setprecision(16) << meanAbsoluteError(pred, actual, n) << endl;
    return 0;
}

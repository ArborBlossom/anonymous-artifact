#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double meanAbsoluteDeviation(double data[], int n) {
    double sum = 0.0;
    double mean;
    double mad = 0.0;
    for (int i = 0; i < n; i++) sum += data[i];
    mean = sum / n;
    for (int i = 0; i < n; i++) mad += fabs(data[i] - mean);
    return mad / n;
}

int main() {
    double data[] = {10.0, 12.0, 23.0, 23.0, 16.0};
    int n = sizeof(data) / sizeof(data[0]);
    meanAbsoluteDeviation(data, n);
    cout << "Mean Absolute Deviation = " << std::scientific << std::setprecision(16) << meanAbsoluteDeviation(data, n) << endl;
    return 0;
}
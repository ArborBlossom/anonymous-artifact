#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double standardDeviation(double data[], int n) {
    double sum = 0.0;
    double mean;
    double sd = 0.0;
    for (int i = 0; i < n; i++) sum += data[i];
    mean = sum / n;
    for (int i = 0; i < n; i++) sd += pow(data[i] - mean, 2);
    return sqrt(sd / n);
}

int main() {
    double data[] = {10.0, 12.0, 23.0, 23.0, 16.0};
    int n = sizeof(data) / sizeof(data[0]);
    standardDeviation(data, n);
    cout << "Standard Deviation = " << std::scientific << std::setprecision(16) << standardDeviation(data, n) << endl;
    return 0;
}
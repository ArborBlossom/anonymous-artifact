#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double standardError(double data[], int n) {
    double sum=0.0;
    double mean;
    double var=0.0;
    for (int i=0; i<n; i++) sum += data[i];
    mean = sum / n;
    for (int i=0; i<n; i++) var += (data[i] - mean) * (data[i] - mean);
    double stddev = sqrt(var / (n - 1));
    return stddev / sqrt(n);
}

int main() {
    double data[] = {78.53, 79.62, 80.25, 81.05, 83.21, 83.46};
    int n = sizeof(data) / sizeof(data[0]);
    standardError(data, n);
    cout << "Standard Error = " << std::scientific << std::setprecision(16) << standardError(data, n) << endl;
    return 0;
}
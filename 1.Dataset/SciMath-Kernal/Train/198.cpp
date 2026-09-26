#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double weightedGeometricMean(double values[], double weights[], int n) {
    double product = 1.0;
    double weightSum = 0.0;
    for (int i = 0; i < n; i++) {
        product *= pow(values[i], weights[i]);
        weightSum += weights[i];
    }
    return pow(product, 1.0/weightSum);
}

int main() {
    double values[] = {2.0, 4.0, 8.0};
    double weights[] = {1.0, 2.0, 3.0};
    int n = sizeof(values)/sizeof(values[0]);
    double wgmean = weightedGeometricMean(values, weights, n);
    cout << "加权几何平均数 = " << std::scientific << std::setprecision(16) << wgmean << endl;
    return 0;
}
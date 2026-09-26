#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double weightedAverage(double values[], double weights[], int n) {
    double weighted_sum = 0.0;
    double weight_sum = 0.0;
    for (int i=0; i<n; i++) {
        weighted_sum += values[i] * weights[i];
        weight_sum += weights[i];
    }
    return weighted_sum / weight_sum;
}

int main() {
    double values[] = {85.0, 90.0, 78.0, 92.0, 88.0};
    double weights[] = {0.1, 0.2, 0.25, 0.15, 0.3};
    int n = sizeof(values) / sizeof(values[0]);
    double wAvg = weightedAverage(values, weights, n);
    cout << "加权平均 = " << std::scientific << std::setprecision(16) << wAvg << endl;
    return 0;
}
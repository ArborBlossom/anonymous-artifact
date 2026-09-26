#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double mean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += data[i];
    return sum / n;
}

double kurtosis(double data[], int n) {
    double m = mean(data, n);
    double sum4 = 0.0;
    double sum2 = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = data[i] - m;
        sum4 += diff * diff * diff * diff;
        sum2 += diff * diff;
    }
    double variance = sum2 / (n - 1);
    return (sum4 / n) / (variance * variance) - 3;
}

int main() {
    double data[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    int n = sizeof(data) / sizeof(data[0]);
    double kurt = kurtosis(data, n);
    cout << "峰度 = " << std::scientific << std::setprecision(16) << kurt << endl;
    return 0;
}
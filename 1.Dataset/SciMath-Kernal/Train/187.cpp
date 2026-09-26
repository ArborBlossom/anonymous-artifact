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

double skewness(double data[], int n) {
    double m = mean(data, n);
    double sum2 = 0.0;
    double sum3 = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = data[i] - m;
        sum3 += diff * diff * diff;
        sum2 += diff * diff;
    }
    double variance = sum2 / (n - 1);
    double stdDev = sqrt(variance);
    return (sum3 / n) / pow(stdDev, 3);
}

int main() {
    double data[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    int n = sizeof(data) / sizeof(data[0]);
    double skew = skewness(data, n);
    cout << "偏度 = " << std::scientific << std::setprecision(16) << skew << endl;
    return 0;
}
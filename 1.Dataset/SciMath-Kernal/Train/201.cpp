#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double covariance(double x[], double y[], int n) {
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }
    return (sumXY - sumX*sumY/n) / n;
}

int main() {
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {2.0, 4.0, 5.0, 4.0, 6.0};
    int n = sizeof(x)/sizeof(x[0]);
    double cov = covariance(x, y, n);
    cout << "协方差 = " << std::scientific << std::setprecision(16) << cov << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double covariance(double X[], double Y[], int n) {
    double sumX=0.0;
    double sumY=0.0;
    double sumXY=0.0;
    for (int i=0; i<n; i++) {
        sumX += X[i];
        sumY += Y[i];
        sumXY += X[i]*Y[i];
    }
    double meanX = sumX / n;
    double meanY = sumY / n;
    return (sumXY / n) - (meanX * meanY);
}

int main() {
    double X[] = {43, 21, 25, 42, 57, 59};
    double Y[] = {99, 65, 79, 75, 87, 81};
    int n = sizeof(X) / sizeof(X[0]);
    covariance(X, Y, n);
    cout << "Covariance = " << std::scientific << std::setprecision(16) << covariance(X1, Y1, n) << endl;
    return 0;
}
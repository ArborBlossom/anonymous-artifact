#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void skewnessKurtosis(double arr[], int n, double *skew) {
    double mean=0.0;
    double m2=0.0;
    double m3=0.0;
    for(int i=0;i<n;i++) mean += arr[i];
    mean /= n;
    for(int i=0;i<n;i++) {
        double d = arr[i] - mean;
        m2 += d*d;
        m3 += d*d*d;
    }
    double s2 = m2 / n;
    double s = sqrt(s2);
    *skew = (m3 / n) / (s2 * s);
}

int main() {
    double arr[] = {2.0, 8.0, 5.0, 7.0, 3.0, 6.0};
    int n = sizeof(arr)/sizeof(arr[0]);
    double skew;
    skewnessKurtosis(arr, n, &skew);
    cout << "Skewness = " << std::scientific << std::setprecision(16) << skew << endl;
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double mean(double arr[], int n) {
    double s1 = 0.0;
    for (int i = 0; i < n; i++) s1 += arr[i];
    return s1 / n;
}

double stddev(double arr[], int n, double mu) {
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += (arr[i] - mu) * (arr[i] - mu);
    return sqrt(s / (n - 1));
}

int main() {
    double arr[] = {10.0, 12.0, 23.0, 23.0, 16.0, 23.0};
    int n = sizeof(arr) / sizeof(arr[0]);
    double mu0 = mean(arr, n);
    double sd = stddev(arr, n, mu0);
    double cv = sd / mu0;
    cout << "CV = " << std::scientific << std::setprecision(16) << cv << endl;
    return 0;
}
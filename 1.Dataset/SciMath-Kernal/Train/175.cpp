#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double mean(double arr[], int n) {
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double stdDev(double arr[], int n) {
    double m = mean(arr, n);
    double sumSq = 0.0;
    for (int i=0; i<n; i++) {
        double diff = arr[i] - m;
        sumSq += diff * diff;
    }
    return sqrt(sumSq / n);
}

int main() {
    double arr[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    int n = sizeof(arr) / sizeof(arr[0]);
    double sd = stdDev(arr, n);
    cout << "标准差 = " << std::scientific << std::setprecision(16) << sd << endl;
    return 0;
}
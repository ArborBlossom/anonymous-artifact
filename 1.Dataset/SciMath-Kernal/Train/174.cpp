#include <stdio.h>
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

double variance(double arr[], int n) {
    double m = mean(arr, n);
    double var_sum = 0.0;
    for (int i=0; i<n; i++) {
        double diff = arr[i] - m;
        var_sum += diff * diff;
    }
    return var_sum / n;
}

int main() {
    double arr[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    int n = sizeof(arr) / sizeof(arr[0]);
    double var = variance(arr, n);
    cout << "数组方差 = " << std::scientific << std::setprecision(16) << var << endl;
    return 0;
}
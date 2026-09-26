#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double sumArray(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int main() {
    double arr[] = {1.2, 2.3, 3.4, 4.5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sumArray(arr, n);
    cout << "Sum = " << std::scientific << std::setprecision(16) << sumArray(arr, n) << endl;
    return 0;
}
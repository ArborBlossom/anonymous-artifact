#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void findMinMax(double data[], int n, double* max) {
    *max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > *max)
            *max = data[i];
    }
}

int main() {
    double data[] = {2.5, 3.1, 1.4, 7.6, 0.9};
    int n = sizeof(data) / sizeof(data[0]);
    double max;
    findMinMax(data, n, &max);
    cout << "最大值 = " << std::scientific << std::setprecision(16) << max << endl;
    return 0;
}
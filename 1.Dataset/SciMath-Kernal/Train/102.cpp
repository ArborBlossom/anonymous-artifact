#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double geometricMean(double data[], int n) {
    double logSum = 0.0;
    for (int i = 0; i < n; i++)
        logSum += log(data[i]);
    return exp(logSum / n);
}

int main() {
    double data[] = {2.0, 8.0, 4.0, 16.0};
    int size = sizeof(data) / sizeof(data[0]);
    geometricMean(data, size);
    cout << "几何平均值 = " << std::scientific << std::setprecision(16) << geometricMean(data, size) << endl;
    return 0;
}
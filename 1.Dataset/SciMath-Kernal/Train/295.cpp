#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double mean(double data[], int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) s += data[i];
    return s / n;
}

int main() {
    double data[] = {10.0, 12.0, 23.0, 23.0, 16.0, 23.0};
    int n = sizeof(data) / sizeof(data[0]);
    double mu = mean(data, n);
    cout << "Mean = " << std::scientific << std::setprecision(16) << mu << endl;
    return 0;
}
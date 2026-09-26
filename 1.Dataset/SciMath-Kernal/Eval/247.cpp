#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double minkowski(double v1[], double v2[], int n, double p) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += pow(fabs(v1[i] - v2[i]), p);
    return pow(sum, 1.0 / p);
}

int main() {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 6.0, 8.0};
    int n = 3;
    double pp = 3.0;
    double dist = minkowski(v1, v2, n, pp);
    cout << "Minkowski distance (p) = " << std::scientific << std::setprecision(16) << dist << endl;
    return 0;
}
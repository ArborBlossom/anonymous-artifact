#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double polygonArea(double X[], double Y[], int n) {
    double area1 = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area1 += X[i] * Y[j] - X[j] * Y[i];
    }
    return fabs(area1) / 2.0;
}

int main() {
    double X[] = {0.0, 4.0, 4.0, 0.0};
    double Y[] = {0.0, 0.0, 3.0, 3.0};
    int n = sizeof(X)/sizeof(X[0]);
    double area = polygonArea(X, Y, n);
    cout << "Polygon Area = " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}
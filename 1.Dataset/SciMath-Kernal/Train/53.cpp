#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double pearson(int x[], int y[], int n) {
    int sum_x = 0, sum_y = 0, sum_xy = 0;
    int squareSum_x = 0, squareSum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        squareSum_x += x[i] * x[i];
        squareSum_y += y[i] * y[i];
    }
    double num = n * sum_xy - sum_x * sum_y;
    double den = sqrt((n * squareSum_x - sum_x * sum_x) * (n * squareSum_y - sum_y * sum_y));
    return num / den;
}

int main() {
    int X[] = {43, 21, 25, 42, 57, 59};
    int Y[] = {99, 65, 79, 75, 87, 81};
    int n = sizeof(X) / sizeof(X[0]);
    pearson(X, Y, n);
    cout << "Pearson correlation = " << std::scientific << std::setprecision(16) << pearson(X, Y, n) << endl;
    return 0;
}

#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double newtonForward(double x[], double y[], int n, double xi) {
    double diff[10][10];
    for (int i = 0; i < n; i++) diff[0][i] = y[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n-i; j++)
            diff[i][j] = diff[i-1][j+1] - diff[i-1][j];
    double h = x[1] - x[0];
    double u = (xi - x[0]) / h;
    double result = diff[0][0];
    for (int i = 1; i < n; i++) {
        double term = diff[i][0];
        for (int j = 0; j < i; j++)
            term *= (u - j) / (j + 1);
        result += term;
    }
    return result;
}

int main() {
    double x[] = {0, 1, 2, 3};
    double y[] = {1, 2, 4, 8};
    double xi1 = 2.5;
    double yi = newtonForward(x, y, 4, xi1);
    cout << "Forward Interpolated at xi: " << std::scientific << std::setprecision(16) << yi << endl;
    return 0;
}
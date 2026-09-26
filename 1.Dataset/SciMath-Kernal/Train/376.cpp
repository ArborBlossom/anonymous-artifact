#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void surfaceGravity(double M[], double R[], int n, double g[]) {
    const double G = 6.67430e-11;
    for (int i=0; i<n; i++)
        g[i] = G * M[i] / (R[i]*R[i]);
}

int main() {
    double M[] = {5.97e24, 7.35e22, 1.90e27}; // 地球、月球、木星 kg
    double R[] = {6.37e6, 1.74e6, 6.99e7};    // m
    int n = sizeof(M)/sizeof(M[0]);
    double g[3];
    surfaceGravity(M, R, n, g);
    cout << "g[1] = " << std::scientific << std::setprecision(16) << g[1] << endl;
    return 0;
}
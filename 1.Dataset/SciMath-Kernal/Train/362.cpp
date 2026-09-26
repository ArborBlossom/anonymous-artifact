#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void dragForce(double rho[], double v[], double Cd[], double A[], int n, double F[]) {
    for (int i = 0; i < n; i++)
        F[i] = 0.5 * rho[i] * v[i]*v[i] * Cd[i] * A[i];
}

int main() {
    double rho[] = {1.0,1.2,1.1,1.3,1.0};
    double v[]   = {10.0,20.0,15.0,25.0,30.0};
    double Cd[]  = {0.47,0.47,1.0,0.5,0.3};
    double A[]   = {1.0,0.8,1.2,1.1,0.9};
    int n = 5;
    double F[5];
    dragForce(rho, v, Cd, A, n, F);
    cout << "Drag[0]=" << std::scientific << std::setprecision(16) << F[0] << endl;
    return 0;
}
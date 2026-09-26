#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void multiCI(double P[], double r[], int t[], int n, double A[]) {
    for (int i = 0; i < n; i++)
        A[i] = P[i] * pow(1.0 + r[i], t[i]);
}

int main() {
    double P[] = {1000.0, 2000.0, 5000.0};
    double r[] = {0.05, 0.04, 0.03};
    int t[]    = {5, 10, 3};
    int n = sizeof(P)/sizeof(P[0]);
    double A[3];
    multiCI(P,r,t,n,A);
    cout << "Amount[2] = " << std::scientific << std::setprecision(16) << A[2] << endl;
    return 0;
}
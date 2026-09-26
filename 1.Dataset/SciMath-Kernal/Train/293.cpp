#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void dft(double x[], double Xr[], double Xi[], int n) {
    for (int k = 0; k < n; k++) {
        Xr[k] = Xi[k] = 0.0;
        for (int t = 0; t < n; t++) {
            double angle = 2*M_PI*k*t/n;
            Xr[k] += x[t]*cos(angle);
            Xi[k] -= x[t]*sin(angle);
        }
    }
}

int main() {
    int n = 4;
    double x[] = {1.0, 2.0, 3.0, 4.0};
    double Xr[4];
    double Xi[4];
    dft(x, Xr, Xi, n);
    double freqEnergy = 0.0;
    for (int i = 0; i < n; i++) {
        freqEnergy += (Xr[i]*Xr[i] + Xi[i]*Xi[i]) / n;
    }
    cout << "Freq energy = " << std::scientific << std::setprecision(16) << freqEnergy << endl;
    return 0;
}
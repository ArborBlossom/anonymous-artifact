#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void attenuate(double E0[], double alpha[], double d[], int n, double E[]) {
    for (int i = 0; i < n; i++)
        E[i] = E0[i] * exp(-alpha[i] * d[i]);
}

int main() {
    double E0[]    = {1.0, 0.8, 0.6, 0.4, 0.2};
    double alpha[] = {0.1, 0.2, 0.15,0.05,0.3};
    double d[]     = {1.0, 2.0, 1.5,0.5,2.5};
    int n = sizeof(E0)/sizeof(E0[0]);
    double E[5];
    attenuate(E0, alpha, d, n, E);
    cout << "E[0] = " << std::scientific << std::setprecision(16) << E[0] << endl;
    return 0;
}
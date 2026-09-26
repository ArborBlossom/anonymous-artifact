#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void idealGas(double P[], double V[], double n[], double T[], int m, double ratio[]) {
    for (int i = 0; i < m; i++)
        ratio[i] = P[i]*V[i] / (n[i]*T[i]);
}

int main() {
    int m = 5;
    double P[] = {101325,202650,303975,405300,506625}; // Pa
    double V[] = {0.0224,0.0224,0.0224,0.0224,0.0224}; // m³
    double n[] = {1,2,3,4,5};                          // mol
    double T[] = {273.15,546.3,819.45,1092.6,1365.75}; // K
    // double R = 8.314462618;
    double ratio[5];
    idealGas(P, V, n, T, m, ratio);
    cout << "P·V/(n·T) = ratio[i] J/(mol·K)\n" << std::scientific << std::setprecision(16) << ratio[0] << endl;
    return 0;
}
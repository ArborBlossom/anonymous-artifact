#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double parallelResistance(double R[], int n) {
    double invSum = 0.0;
    for (int i = 0; i < n; i++)
        invSum += 1.0 / R[i];
    return 1.0 / invSum;
}

int main() {
    double R[] = {100.0, 200.0, 300.0, 400.0, 500.0};
    int n = sizeof(R)/sizeof(R[0]);
    double Req = parallelResistance(R, n);
    cout << "Equivalent Parallel Resistance = " << std::scientific << std::setprecision(16) << Req << endl;
    return 0;
}
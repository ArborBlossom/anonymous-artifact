#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double bbpPi(int n) {
    double sum = 0.0;
    for (int k = 0; k < n; k++)
        sum += (1.0/pow(16,k)) *
               (4.0/(8*k+1) - 2.0/(8*k+4) - 1.0/(8*k+5) - 1.0/(8*k+6));
    return sum;
}

int main() {
    double pi = bbpPi(10);
    cout << "BBP π ≈ " << std::scientific << std::setprecision(16) << pi << endl;
    return 0;
}
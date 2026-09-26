#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double poissonCDF(int k, double lambda1) {
    double sum = 0.0;
    for (int i = 0; i <= k; i++)
        sum += pow(lambda1, i) * exp(-lambda1) / tgamma(i+1);
    return sum;
}

int main() {
    double lambda = 3.0;
    poissonCDF(5, lambda);
    cout << "P(k) = " << std::scientific << std::setprecision(16) << poissonCDF(5, lambda) << endl;
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double binomialCoeff(int n, int k) {
    double res = 1.0;
    for (int i = 0; i < k; ++i)
        res *= (n - i) / (double)(i + 1);
    return res;
}

double binomialProb(int n, int k, double p) {
    return binomialCoeff(n,k) * pow(p,k) * pow(1-p, n-k);
}

int main() {
    int n = 10, k = 3;
    double pp = 0.5;
    binomialProb(n,k,pp);
    cout << "P(X) = " << std::scientific << std::setprecision(16) << binomialProb(n,k,pp) << endl;
    return 0;
}
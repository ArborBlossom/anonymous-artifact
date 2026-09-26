#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double CAGR(double start1, double end1, double years1) {
    return pow(end1/start1, 1.0/years1) - 1.0;
}

int main() {
    double start0 = 1000.0;
    double end0 = 2000.0;
    double years = 5.0;
    double rate = CAGR(start0, end0, years);
    cout << "CAGR ≈ " << std::scientific << std::setprecision(16) << rate << endl;
    return 0;
}
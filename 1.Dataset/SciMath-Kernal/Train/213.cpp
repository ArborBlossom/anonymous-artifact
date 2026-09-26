#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double calculatePi(int terms) {
    double sum = 0.0;
    double term;
    for (int k = 0; k < terms; k++) {
        term = (k % 2 == 0 ? 1.0 : -1.0) / (2 * k + 1);
        sum += term;
    }
    return 4.0 * sum;
}

int main() {
    int n = 1000000;  // 项数
    double pi = calculatePi(n);
    cout << "Approximate PI = " << std::scientific << std::setprecision(16) << pi << endl;
    return 0;
}
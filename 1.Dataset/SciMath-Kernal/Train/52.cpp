#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double power(double base, int exp) {
    double result = 1.0;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    double a = 2.0;
    int b = 10;
    power(a, b);
    cout << std::scientific << std::setprecision(16) << power(a, b) << endl;
    return 0;
}
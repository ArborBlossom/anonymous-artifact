#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double a = 1.0 / 3.0;
    double b = 2.0 / 7.0;
    cout << "a + b = " << std::scientific << std::setprecision(16) << a + b << endl;
    return 0;
}
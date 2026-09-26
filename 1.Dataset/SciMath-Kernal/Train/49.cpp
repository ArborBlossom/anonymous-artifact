#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double vectorMagnitude(double x1, double y1) {
    return sqrt(x1 * x1 + y1 * y1);
}

int main() {
    double x = 3.0;
    double y = 4.0;
    vectorMagnitude(x, y);
    cout << "Magnitude: " << std::scientific << std::setprecision(16) << vectorMagnitude(x, y) << endl;
    return 0;
}

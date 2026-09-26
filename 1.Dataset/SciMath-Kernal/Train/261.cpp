#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void cartesianToPolar(double x1, double y1, double *r) {
    *r = sqrt(x1*x1 + y1*y1);
}

int main() {
    double x = 3.0;
    double y = 4.0;
    double r;
    cartesianToPolar(x, y, &r);
    cout << "Polar: r = " << std::scientific << std::setprecision(16) << r << endl;
    return 0;
}
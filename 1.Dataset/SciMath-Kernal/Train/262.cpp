#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void cartesianToPolar(double x1, double y1, double *theta) {
    *theta = atan2(y1, x1);
}

int main() {
    double x = 3.0;
    double y = 4.0;
    double theta;
    cartesianToPolar(x, y, &theta);
    cout << "Polar: θ = " << std::scientific << std::setprecision(16) << theta << endl;
    return 0;
}
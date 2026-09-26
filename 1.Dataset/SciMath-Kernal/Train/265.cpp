#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double parabolaSegmentArea(double a, double b) {
    // ∫₀ᵇ x² dx = b³/3
    return (b*b*b) / 3.0 - a*a*a / 3.0;
}

int main() {
    double aa = 1.0;
    double bb = 2.0;
    double area = parabolaSegmentArea(aa, bb);
    cout << "Parabola segment area between a and b = " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}
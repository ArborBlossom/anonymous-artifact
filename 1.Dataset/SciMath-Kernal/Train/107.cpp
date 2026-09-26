#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double pointToLineDistance(double x, double y, double a, double b, double c) {
    return fabs(a * x + b * y + c) / sqrt(a * a + b * b);
}

int main() {
    pointToLineDistance(3, 4, 1, -1, -2);
    cout << "距离 = " << std::scientific << std::setprecision(16) << pointToLineDistance(3, 4, 1, -1, -2) << endl;
    return 0;
}
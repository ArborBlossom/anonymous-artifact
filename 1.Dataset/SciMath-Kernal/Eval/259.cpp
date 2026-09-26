#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double circularSegmentArea(double r1, double theta1) {
    // θ 以弧度表示
    return 0.5 * r1 * r1 * (theta1 - sin(theta1));
}

int main() {
    double r = 5.0;
    double theta = M_PI / 3.0;  // 60°
    double area = circularSegmentArea(r, theta);
    cout << "Circular segment area = " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double heronArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double aa = 3.0;
    double bb = 4.0;
    double cc = 5.0;
    double area = heronArea(aa, bb, cc);
    cout << "三角形边长 a, b, c 的面积 = " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}
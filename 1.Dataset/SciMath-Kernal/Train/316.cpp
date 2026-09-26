#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void circumcircle(double x1,double y1,double x2,double y2,double x3,double y3,double center[2], double *r) {
    double d = 2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    double ux = ((x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2)) / d;
    double uy = ((x1*x1+y1*y1)*(x3-x2)+(x2*x2+y2*y2)*(x1-x3)+(x3*x3+y3*y3)*(x2-x1)) / d;
    center[0] = ux; center[1] = uy;
    *r = sqrt((ux-x1)*(ux-x1)+(uy-y1)*(uy-y1));
}

int main() {
    double center[2];
    double r;
    circumcircle(0,0, 4,0, 0,3, center, &r);
    cout << "Radius = " << std::scientific << std::setprecision(16) << rr << endl;
    return 0;
}
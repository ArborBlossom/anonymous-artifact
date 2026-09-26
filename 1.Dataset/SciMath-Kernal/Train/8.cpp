#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


#define M_PI       3.14159265358979323846

int main() {
    double x=1.7;
    double y=2.9;
    double angle = atan2(y,x) * 180.0 / M_PI;
    cout << "Angle: " << std::scientific << std::setprecision(16) << angle << " degree" << endl;
    return 0;
}
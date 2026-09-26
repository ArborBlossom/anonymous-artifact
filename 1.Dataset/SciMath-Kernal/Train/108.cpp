#include <stdio.h>
#define PI 3.1415926535
#include <iostream>//
#include <iomanip> //
using namespace std;//

double degToRad(double deg) {
    return deg * PI / 180.0;
}

int main() {
    double angle_deg = 60.0;
    degToRad(angle_deg);
    cout << "degToRad " << std::scientific << std::setprecision(16) << degToRad(angle_deg) << endl;
    return 0;
}
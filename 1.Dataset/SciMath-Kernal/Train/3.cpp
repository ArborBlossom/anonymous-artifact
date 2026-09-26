#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


#define M_PI       3.14159265358979323846

int main() {
    double v = 20.0;      // 初速度 m/s
    double theta = 30.0;  // 发射角度 (度)
    const double g = 9.8;
    double rad = theta * M_PI / 180.0;
    double range = (v * v * sin(2 * rad)) / g;
    cout << "Range: " << std::scientific << std::setprecision(16) << range << " m" << endl;
    return 0;
}
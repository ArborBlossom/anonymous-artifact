#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


#define M_PI       3.14159265358979323846

int main() {
    double r = 3.0;  // 半径 m
    double h = 5.0;  // 高度 m
    double volume = (1.0/3.0) * M_PI * r * r * h;
    cout << "Volume of Cone: " << std::scientific << std::setprecision(16) << volume << " m^3" << endl;
    return 0;
}
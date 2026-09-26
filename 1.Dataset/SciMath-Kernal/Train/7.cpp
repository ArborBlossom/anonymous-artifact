#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


#define M_PI       3.14159265358979323846

int main() {
    double R = 5.0;  // 主半径
    double r = 2.0;  // 管半径
    double volume = 2 * M_PI * M_PI * R * r * r;
    cout << "Volume of Torus: " << std::scientific << std::setprecision(16) << volume << endl;
    return 0;
}
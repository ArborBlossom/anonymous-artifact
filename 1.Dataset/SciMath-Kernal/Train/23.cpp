#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);
int main() {
    double s = 1414.21356237; //deepseek编写值
    double a = 81.028338470;
    string unit = "min";
    const double r = 6440.0;
    if (unit == "min") a /= 60.0;
    if (a > 180.0) a = 360.0 - a;
    double arc = 2.0 * PI * (r + s) * a / 360.0;
    cout << fixed << std::scientific << std::setprecision(16) << arc << endl;
    return 0;
}
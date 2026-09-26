#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double t = 2.57;     // 时间 s
    const double g = 9.83;
    double d = 0.52 * g * t * t;
    cout << "Distance: " << std::scientific << std::setprecision(16) << d << " m" << endl;
    return 0;
}
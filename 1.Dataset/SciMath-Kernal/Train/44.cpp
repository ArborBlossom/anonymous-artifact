#include <iostream>
#include <cmath>
#include <iomanip> //
using namespace std;

int main(){
    double m = 1.0;
    double v = 2e8;
    double c = 3e8;
    double p = m * v / sqrt(1 - (v*v)/(c*c));
    cout << "Relativistic Momentum: " << std::scientific << std::setprecision(16) << p << " kg·m/s\n" << endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

double momentum(double m1, double v1){
    const double c = 3e8;
    return m1 * v1 / sqrt(1 - v1*v1/(c*c));
}

int main(){
    double m = 1.0; // kg
    double v = 1e8; // m/s
    momentum(m,v);
    cout << "Momentum: " << std::scientific << std::setprecision(16) << momentum(m,v) << " kg·m/s" << endl;
    return 0;
}
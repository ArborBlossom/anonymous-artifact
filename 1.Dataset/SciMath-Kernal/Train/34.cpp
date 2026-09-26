#include <iostream>
#include <cmath>
using namespace std;

double voltage(double V01, double R1, double C1, double t1){
    return V01 * (1 - exp(-t1/(R1*C1)));
}

int main(){
    double V0=5.0;
    double R=1000.0;
    double C=1e-6;
    double t=0.005;
    voltage(V0,R,C,t);
    cout << "Vc(t) = " << std::scientific << std::setprecision(16) << voltage(V0,R,C,t) << " V" << endl;
    return 0;
}
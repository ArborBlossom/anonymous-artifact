#include <iostream>
#include <iomanip> //
using namespace std;

double kalmanGain(double P1, double R1){
    return P1 / (P1 + R1);
}

int main(){
    double P=1.0;
    double R=0.5;
    kalmanGain(P,R);
    cout << "Kalman Gain: " << std::scientific << std::setprecision(16) << kalmanGain(P,R) << endl;
    return 0;
}

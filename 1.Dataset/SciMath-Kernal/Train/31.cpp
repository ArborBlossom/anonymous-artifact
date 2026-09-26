#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double gamma = 1.4;     // 比热比
    double R = 287.0;       // 气体常数
    double T = 300.0;       // 温度 K
    double c = sqrt(gamma * R * T);
    cout << "Speed of sound: " << std::scientific << std::setprecision(16) << c << " m/s" << endl;
    return 0;
}

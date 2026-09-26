#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double downstream = 20.0; // 顺水速度 km/h
    double upstream = 12.0;   // 逆水速度 km/h
    double speed_boat = (downstream + upstream) / 2;
    cout << "船速： " << std::scientific << std::setprecision(16) << speed_boat << endl;
    return 0;
}
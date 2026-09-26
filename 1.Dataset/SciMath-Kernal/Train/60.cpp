#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double downstream = 20.0; // 顺水速度 km/h
    double upstream = 12.0;   // 逆水速度 km/h
    double speed_stream = (downstream - upstream) / 2;
    cout << "水流速度： " << std::scientific << std::setprecision(16) << speed_stream << endl;
    return 0;
}
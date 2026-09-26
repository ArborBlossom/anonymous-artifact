#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double dphi = 0.05; // 磁通量变化 Wb
    double dt = 0.1;    // 时间变化 s
    double EMF = -dphi / dt; // 感应电动势 V
    cout << "感应电动势: " << std::scientific << std::setprecision(16) << EMF << endl;
    return 0;
}
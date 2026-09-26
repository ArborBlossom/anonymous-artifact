#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double freq = 2.4e9; // 频率 Hz
    double dist = 100.0; // 距离 m
    double c = 3e8;
    double loss = 20 * log10(dist) + 20 * log10(freq) - 147.55;
    cout << "路径损耗（dB）= " << std::scientific << std::setprecision(16) << loss << endl;
    return 0;
}
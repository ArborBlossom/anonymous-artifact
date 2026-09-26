#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double result;

// 用泰勒级数近似计算 sin(x)
void cal_sin(double n1) {
    double acc = 0.0001;
    double denominator;
    double sinx;
    double sinval;
    n1 = n1 * (3.142 / 180.0);
    double temp = n1; 
    sinx = n1; 
    sinval = sin(n1);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i + 1);
        temp = -temp * n1 * n1 / denominator;
        sinx += temp;
        i++;
    } while (acc <= fabs(sinval - sinx));
    result = sinx;
}

int main() {
    double n = 30;
    cal_sin(n);

    cout << "Sin: " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}
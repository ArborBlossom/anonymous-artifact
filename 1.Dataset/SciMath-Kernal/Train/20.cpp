#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double result;


// 用泰勒级数近似计算 cos(x)
void cal_cos(double n1) {
    double acc = 0.0001;
    double temp = 1;
    double denominator;
    double cosx;
    double cosval;
    n1 = n1 * (3.142 / 180.0);
    cosx = temp; cosval = cos(n1);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i - 1);
        temp = -temp * n1 * n1 / denominator;
        cosx += temp;
        i++;
    } while (acc <= fabs(cosval - cosx));
    result = cosx;
}

int main() {
    double n = 60;
    cal_cos(n);
    cout << "Cos: " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}
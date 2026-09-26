#include <iostream>
#include <cmath>
using namespace std;


double fact(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

double ber(int n) {
    double s = 0;
    for (int p = 1; p <= 20; p++)
        s += pow(p, -2 * n);
    return pow(-1, n - 1) * 2 * fact(2 * n) * s / (pow(2 * M_PI, 2 * n));
}

double mytan(double x_p1, int n) {
    double s2 = 0;
    for (int i = 0; i <= n; i++)
        s2 += (pow(-1, i - 1) * pow(2, 2 * i) * (pow(2, 2 * i) - 1) * ber(i) * pow(x_p1, 2 * i - 1)) / fact(2 * i);
    return s2;
}

int main() {
    double x = 71.945689;

    double result = mytan(x, 20);
    cout << result;  

    return 0;
}

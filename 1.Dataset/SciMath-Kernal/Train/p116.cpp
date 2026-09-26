#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
    double y = 1.0 / (1 + x * x);
    return y;
}
int main() {
    int a = 42, b = 32;

    int n = 6;

    double h = (b - a) / (n * 1.0);
    double y0 = f(a);
    double yn = f(a + h * n);
    double result = 0.0;
    for (int i = 1; i < n; i++) {
        result += (f(a + h * i));
    }
    result *= 2;
    result += (y0 + yn);
    result *= (h / 2.0);
    cout << result << "\n";

    return 0;
}

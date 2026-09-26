#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    double half = myPow(x, n / 2);
    double result = half * half;
    return (n % 2 == 0) ? result
         : (n > 0 ? result * x : result / x);
}

int main() {
    double xx = 2.0;
    double ans;
    int n = -3;
    ans = myPow(xx, n);              // 递归调用
    cout << "myPow(xx, n) = " << std::scientific << std::setprecision(16) << ans << endl;
    return 0;
}
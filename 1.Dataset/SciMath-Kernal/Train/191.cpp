#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) {
    return 1.0/(1.0 + x1*x1); // 函数：1/(1+x^2)
}

double simpsons(double a, double b, int n) {
    double h = (b - a)/n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        if (i % 2 == 0)
            sum += 2*f(x);
        else
            sum += 4*f(x);
    }
    
    return (h/3)*sum;
}

int main() {
    double aa = 0.0;
    double bb = 1.0;
    int n = 6; // 间隔数（必须为偶数）
    simpsons(aa, bb, n);
    cout << "积分值: " << std::scientific << std::setprecision(16) << simpsons(aa, bb, n) << endl;
    return 0;
}
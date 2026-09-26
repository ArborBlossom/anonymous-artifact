#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

#define MAX_ITER 10

double f(double x) {
    return exp(-x*x); // 高斯函数
}

double romberg(double a, double b) {
    double R[MAX_ITER][MAX_ITER];
    double h = b - a;
    // 第一列（梯形法则）
    R[0][0] = (h/2)*(f(a) + f(b));
    for (int i = 1; i < MAX_ITER; i++) {
        h /= 2;
        double sum = 0.0;
        int steps = pow(2, i-1);
        for (int k = 1; k <= steps; k++) {
            sum += f(a + (2*k - 1)*h);
        }
        R[i][0] = 0.5*R[i-1][0] + h*sum;
        // Richardson外推法
        for (int j = 1; j <= i; j++) {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1])/(pow(4, j) - 1);
        }
    }
    return R[MAX_ITER-1][MAX_ITER-1];
}

int main() {
    double aa = -1.0;
    double bb = 1.0;
    romberg(aa, bb);
    cout << "龙贝格积分结果: " << std::scientific << std::setprecision(16) << romberg(aa, bb) << endl;
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lambertW(double x) {
    double w = log(1 + x);  // 初始猜测
    for (int i = 0; i < 10; i++) {
        double e = exp(w);
        w = w - (w*e - x)/(e*(w+1) - (w+2)*(w*e - x)/(2*w+2));
    }
    return w;
}

int main() {
    double xx = 1.0;
    double ww = lambertW(xx);
    cout << "Lambert W(x) ≈ " << std::scientific << std::setprecision(16) << ww << endl;
    return 0;
}
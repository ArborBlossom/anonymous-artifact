#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double E2(double phi, double m, int n) {
    // ∫₀ᵖʰⁱ √(1-m sin²θ) dθ 用复合梯形
    int N = n;
    double h = phi / N;
    double sum = 0.5*(sqrt(1-m*sin(0)*sin(0)) + sqrt(1-m*sin(phi)*sin(phi)));
    for (int i = 1; i < N; i++) {
        double th = i*h;
        sum += sqrt(1 - m*sin(th)*sin(th));
    }
    return sum * h;
}

int main() {
    double val = E2(M_PI/2, 0.5, 1000);
    cout << "E(phi=π/2,m=0.5) ≈ " << std::scientific << std::setprecision(16) << val << endl;
    return 0;
}
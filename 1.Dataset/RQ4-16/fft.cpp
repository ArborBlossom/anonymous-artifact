#include <cmath>
#include <complex>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);

void fft(int n, int step, std::complex<double>* a) {
    if (step < n) {
        fft(n, step * 2, a);
        fft(n, step * 2, a + step);
        for (int i = 0; i < n; i += 2 * step) {
            std::complex<double> t = std::polar(1.0, -PI * i / n) * a[i + step];
            a[i + step] = a[i] - t;
            a[i] += t;
        }
    } 
}

int main() {
    const int N = 8;
    std::complex<double> data1[N];

    for (int i = 0; i < N; ++i) {
        double real_part = cos(2 * PI * i / N);
        double imag_part = sin(2 * PI * i / N);
        data1[i] = std::complex<double>(real_part, imag_part);
    }

    fft(N, 1, data1);
    cout << "result: " << std::scientific << std::setprecision(16) << data1[0] << endl;

    return 0;
}
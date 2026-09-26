#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void doubleExpSmooth(double data[], int n, double alpha, double beta, double S[], double B[]) {
    S[0] = data[0];
    B[0] = data[1] - data[0];
    for (int i = 1; i < n; i++) {
        S[i] = alpha * data[i] + (1 - alpha) * (S[i-1] + B[i-1]);
        B[i] = beta  * (S[i] - S[i-1]) + (1 - beta) * B[i-1];
    }
}

int main() {
    double data[] = {3.0, 10.0, 12.0, 13.0, 12.0, 10.0, 12.0};
    int n = sizeof(data)/sizeof(data[0]);
    double S[7];
    double B[7];
    doubleExpSmooth(data, n, 0.8, 0.2, S, B);
    double forecast = S[n-1] + B[n-1];  // k=1 步预测
    cout << "Forecast for t=7: " << std::scientific << std::setprecision(16) << forecast << endl;
    return 0;
}
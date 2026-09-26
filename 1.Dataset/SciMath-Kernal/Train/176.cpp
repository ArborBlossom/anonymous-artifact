#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double dotProduct(double v1[], double v2[], int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

int main() {
    double vec1[] = {1.0, 3.0, -5.0};
    double vec2[] = {4.0, -2.0, -1.0};
    int n = sizeof(vec1) / sizeof(vec1[0]);
    double dp = dotProduct(vec1, vec2, n);
    cout << "向量点积 = " << std::scientific << std::setprecision(16) << dp << endl;
    return 0;
}
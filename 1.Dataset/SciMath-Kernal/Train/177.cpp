#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double euclideanNorm(double vec[], int n) {
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += vec[i]*vec[i];
    }
    return sqrt(sum);
}

int main() {
    double vec[] = {3.0, 4.0};
    int n = sizeof(vec)/sizeof(vec[0]);
    double norm = euclideanNorm(vec, n);
    cout << "向量的欧几里得范数 = " << std::scientific << std::setprecision(16) << norm << endl;
    return 0;
}
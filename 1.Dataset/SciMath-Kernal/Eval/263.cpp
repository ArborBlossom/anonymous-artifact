#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double dotProduct(double v1[], double v2[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += v1[i] * v2[i];
    return sum;
}

double norm1(double v1[], int n) {
    double sum1 = 0.0;
    for (int i = 0; i < n; i++) sum1 += v1[i] * v1[i];
    return sqrt(sum1);
}

double norm2(double v2[], int n) {
    double sum2 = 0.0;
    for (int i = 0; i < n; i++) sum2 += v2[i] * v2[i];
    return sqrt(sum2);
}

int main() {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    int n = 3;
    double dot = dotProduct(v1, v2, n);
    double angle = acos(dot / (norm1(v1,n) * norm2(v2,n)));
    cout << "Angle between vectors = " << std::scientific << std::setprecision(16) << angle << endl;
    return 0;
}
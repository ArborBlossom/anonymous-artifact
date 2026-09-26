#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double euclideanDistance(double vec1[], double vec2[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = vec1[i] - vec2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int main() {
    double vec1[] = {2.0, 3.0, 4.0};
    double vec2[] = {5.0, 6.0, 7.0};
    int n = sizeof(vec1) / sizeof(vec1[0]);
    double dist = euclideanDistance(vec1, vec2, n);
    cout << "欧氏距离 = " << std::scientific << std::setprecision(16) << dist << endl;
    return 0;
}
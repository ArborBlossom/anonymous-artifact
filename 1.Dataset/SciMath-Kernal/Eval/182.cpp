#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double dotProduct(double v1[], double v2[], int n) {
    double dot = 0.0;
    for (int i = 0; i < n; i++)
        dot += v1[i] * v2[i];
    return dot;
}

double vectorNorm1(double v1[], int n) {
    double sum1 = 0.0;
    for (int i = 0; i < n; i++)
        sum1 += v1[i] * v1[i];
    return sqrt(sum1);
}

double vectorNorm2(double v2[], int n) {
    double sum2 = 0.0;
    for (int i = 0; i < n; i++)
        sum2 += v2[i] * v2[i];
    return sqrt(sum2);
}

double cosineSimilarity(double v1[], double v2[], int n) {
    return dotProduct(v1, v2, n) / (vectorNorm1(v1, n) * vectorNorm2(v2, n));
}

int main() {
    double v1[] = {1.0, 0.0, -1.0};
    double v2[] = {1.0, 1.0, 0.0};
    int n = sizeof(v1) / sizeof(v1[0]);
    double cosSim = cosineSimilarity(v1, v2, n);
    cout << "余弦相似度 = " << std::scientific << std::setprecision(16) << cosSim << endl;
    return 0;
}
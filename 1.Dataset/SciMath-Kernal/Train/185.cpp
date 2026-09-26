#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double weightedStdDev(double vals[], double weights[], int n) {
    double sumW=0;
    double sumWV=0;
    double sumWV2=0;
    for (int i=0; i<n; i++) {
        sumW += weights[i];
        sumWV += weights[i]*vals[i];
        sumWV2 += weights[i]*vals[i]*vals[i];
    }
    double mean = sumWV / sumW;
    return sqrt((sumWV2/sumW) - (mean*mean));
}

int main() {
    double vals[] = {10, 20, 30, 40};
    double weights[] = {1, 2, 3, 4};
    int n = sizeof(vals)/sizeof(vals[0]);
    weightedStdDev(vals, weights, n);
    cout << "加权标准差 = " << std::scientific << std::setprecision(16) << weightedStdDev(vals, weights, n) << endl;
    return 0;
}
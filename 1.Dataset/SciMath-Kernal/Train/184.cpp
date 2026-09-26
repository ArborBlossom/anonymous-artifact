#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double pearsonCorrelation(double x[], double y[], int n) {
    double sumX=0;
    double sumY=0;
    double sumXY=0;
    double sumX2=0;
    double sumY2=0;
    for (int i=0; i<n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumX2 += x[i]*x[i];
        sumY2 += y[i]*y[i];
    }
    double numerator = n*sumXY - sumX*sumY;
    double denominator = sqrt((n*sumX2 - sumX*sumX)*(n*sumY2 - sumY*sumY));
    if (denominator == 0) return 0;
    return numerator/denominator;
}

int main() {
    double x[] = {43, 21, 25, 42, 57, 59};
    double y[] = {99, 65, 79, 75, 87, 81};
    int n = sizeof(x)/sizeof(x[0]);
    pearsonCorrelation(x, y, n);
    cout << "皮尔逊相关系数 = " << std::scientific << std::setprecision(16) << pearsonCorrelation(x, y, n) << endl;
    return 0;
}
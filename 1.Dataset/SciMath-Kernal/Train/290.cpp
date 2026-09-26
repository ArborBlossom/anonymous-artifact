#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void weightedCentroid(double x[], double w[], int n, double cx[1]) {
    double sumW = 0.0;
    double sx = 0.0;
    for (int i = 0; i < n; i++) {
        sumW += w[i];
        sx += x[i] * w[i];
    }
    *cx = sx / sumW;
}

int main() {
    double x[] = {0, 2, 4};
    double w[] = {1, 2, 1};
    double cx;
    weightedCentroid(x,w,3,&cx);
    cout << "Weighted Centroid = " << std::scientific << std::setprecision(16) << cx << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void weightedCentroid(double y[], double w[], int n, double cy[1]) {
    double sumW = 0.0;
    double sy = 0.0;
    for (int i = 0; i < n; i++) {
        sumW += w[i];
        sy += y[i] * w[i];
    }
    *cy = sy / sumW;
}

int main() {
    double y[] = {0, 3, 0};
    double w[] = {1, 2, 1};
    double cy;
    weightedCentroid(y,w,3,&cy);
    cout << "Weighted Centroid = " << std::scientific << std::setprecision(16) << cy << endl;
    return 0;
}
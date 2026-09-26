#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double rootMeanSquare(double data[], int n) {
    double sumSquares = 0.0;
    double meanSquares;
    for (int i = 0; i < n; i++) {
        sumSquares += data[i] * data[i];
    }
    meanSquares = sumSquares / n;
    return sqrt(meanSquares);
}

int main() {
    double data[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    int n = sizeof(data) / sizeof(data[0]);
    double rms = rootMeanSquare(data, n);
    cout << "RMS = " << std::scientific << std::setprecision(16) << rms << endl;
    return 0;
}
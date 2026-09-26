#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double rms(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += data[i]*data[i];
    return sqrt(sum / n);
}

int main() {
    double data[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    int n = sizeof(data)/sizeof(data[0]);
    rms(data,n);
    cout << "RMS = " << std::scientific << std::setprecision(16) << rms(data,n) << endl;
    return 0;
}
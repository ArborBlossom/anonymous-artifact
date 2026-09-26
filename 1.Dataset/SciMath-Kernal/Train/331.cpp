#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void haar1D(double data[], int n, double out[]) {
    int half = n/2;
    for (int i = 0; i < half; i++) {
        out[i]      = (data[2*i] + data[2*i+1]) / sqrt(2.0);
        out[half+i] = (data[2*i] - data[2*i+1]) / sqrt(2.0);
    }
}

int main() {
    double data[8] = {5.0,7.0,3.0,1.0,6.0,4.0,2.0,8.0};
    double out[8];
    haar1D(data,8,out);
    cout << "Haar transform: " << std::scientific << std::setprecision(16) << out[6] << endl;
    return 0;
}
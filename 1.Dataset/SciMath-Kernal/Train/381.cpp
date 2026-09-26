#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lambertW(double z) {
    double w = log(z); // 初始
    for (int i=0;i<10;i++)
        w = w - (w*exp(w)-z)/((exp(w)*(w+1))-((w+2)*(w*exp(w)-z)/(2*w+2)));
    return w;
}

int main() {
    double z[] = {0.1,1.0,2.0,5.0};
    int n = sizeof(z)/sizeof(z[0]);
    lambertW(z[3]);
    cout << "W(z[3]) ≈ " << std::scientific << std::setprecision(16) << lambertW(z[3]) << endl;
    return 0;
}
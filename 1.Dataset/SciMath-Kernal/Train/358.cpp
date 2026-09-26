#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void complexMod(double re[], double im[], int n, double mod[]) {
    for (int i = 0; i < n; i++)
        mod[i] = sqrt(re[i]*re[i] + im[i]*im[i]);
}

int main() {
    double re[] = {1.0,2.0,3.0,4.0,5.0};
    double im[] = {0.5,1.5,2.5,3.5,4.5};
    int n = sizeof(re)/sizeof(re[0]);
    double mod[5];
    complexMod(re, im, n, mod);
    cout << "|z[4]| = " << std::scientific << std::setprecision(16) << mod[4] << endl;
    return 0;
}
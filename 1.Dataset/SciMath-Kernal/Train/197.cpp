#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double geometricMean(double data[], int n) {
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        product *= data[i];
    }
    return pow(product, 1.0/n);
}

int main() {
    double data[] = {1.5, 3.0, 6.0};
    int n = sizeof(data)/sizeof(data[0]);
    double gmean = geometricMean(data, n);
    cout << "几何平均数 = " << std::scientific << std::setprecision(16) << gmean << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double harmonicMean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += 1.0 / data[i];
    }
    return n / sum;
}

int main() {
    double data[] = {2.5, 3.0, 10.0, 15.0, 15.0};
    int n = sizeof(data) / sizeof(data[0]);
    double hmean = harmonicMean(data, n);
    cout << "调和平均数 = " << std::scientific << std::setprecision(16) << hmean << endl;
    return 0;
}
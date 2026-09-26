#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void findMinMax(double data[], int n, double* min) {
    *min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < *min)
            *min = data[i];
    }
}

int main() {
    double data[] = {2.5, 3.1, 1.4, 7.6, 0.9};
    int n = sizeof(data) / sizeof(data[0]);
    double min;
    findMinMax(data, n, &min);
    cout << "最小值 = " << std::scientific << std::setprecision(16) << min << endl;
    return 0;
}
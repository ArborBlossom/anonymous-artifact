#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double gini(double dataSets[], int n) {
    double sum=0;
    double sumAbs=0;
    for (int i = 0; i < n; i++) {
        sumAbs += fabs(dataSets[i]);
        for (int j = 0; j < n; j++)
            sum += fabs(dataSets[i] - dataSets[j]);
    }
    return sum / (2.0 * n * n * (sumAbs/n));
}

int main() {
    double dataSets[2][5] = {
        {10,20,30,40,50},
        {1,2,2,3,8}
    };
    gini(dataSets[1], 5);
    cout << "Gini[2] = " << std::scientific << std::setprecision(16) << gini(dataSets[1], 5) << endl;
    return 0;
}
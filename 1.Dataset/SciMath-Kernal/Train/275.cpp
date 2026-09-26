#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double sumPower(int n, double p) {
    double sum = 0.0;
    for (int k = 1; k <= n; k++)
        sum += pow((double)k, p);
    return sum;
}

int main() {
    int n = 100;
    double pp = 2.0;
    double s = sumPower(n, pp);
    cout << "Sum k^p for k=1 to n = " << std::scientific << std::setprecision(16) << s << endl;
    return 0;
}
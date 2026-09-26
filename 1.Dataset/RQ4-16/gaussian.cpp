#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double gaussian(double x, double mean, double stddev) {
    double variance = pow(stddev, 2);
    double coeff = 1.0 / (sqrt(2.0 * M_PI * variance));
    double exponent = -pow(x - mean, 2) / (2.0 * variance);
    return coeff * exp(exponent);
}

int main() {
    double x = 0.0; 
    double mean = 0.0; 
    double stddev = 1.0; 
    double result = gaussian(x, mean, stddev);

    cout << "result: " << std::scientific << std::setprecision(16) << result << endl;

    return 0;
}

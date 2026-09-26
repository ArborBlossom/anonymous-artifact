#include <iostream>
#include <cmath>
using namespace std;

double a = 25.059730;
double b = 42.909820;
double x = 0.215302;

int main() {
    double z = sqrt(a * x * sin(2 * x) + exp(-2 * x) * (x + b));

    cout << z << "\n";  

    return 0;
}

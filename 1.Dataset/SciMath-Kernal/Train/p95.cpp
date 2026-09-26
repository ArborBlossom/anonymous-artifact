#include <iostream>
#include <cmath>
using namespace std;

double sumOfGP(double a_p1, double r_p1, int n) {
    return (a_p1 * (1 - pow(r_p1, n))) / (1 - r_p1);
}

int main() {
    double a = 52.032296; 
    double r = 2.763320; 

    int n = 15;

    double result = sumOfGP(a, r, n);
    cout << result;   

    return 0;
}

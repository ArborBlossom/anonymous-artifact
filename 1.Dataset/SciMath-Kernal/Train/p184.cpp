#include <iostream>
using namespace std;


double rnd1(double *r) {
    int m;
    double s = 65536.0;
    double u = 2053.0;
    double v = 13849.0;
    m = static_cast<int>(*r / s);
    *r = *r - m * s;
    *r = u * (*r) + v;
    m = static_cast<int>(*r / s);
    *r = *r - m * s;
    double p = *r / s;
    return p;
}

int main() {
    double r = -44.816418;

    double last = 0;
    for (int i = 0; i <= 9; i++)
        last = rnd1(&r);
    cout << last << endl; 

    return 0;
}

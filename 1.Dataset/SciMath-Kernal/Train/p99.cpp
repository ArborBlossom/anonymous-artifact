#include <iostream>
#include <cmath>
using namespace std;

#define EPSILON 0.001
double func(double x_func) {
    return x_func * x_func * x_func - x_func * x_func + 2;
}

double derivFunc(double x_derivFunc) {
    return 3 * x_derivFunc * x_derivFunc - 2 * x_derivFunc;
}

double newtonRaphson(double x_newtonRaphson) {
    double h = func(x_newtonRaphson) / derivFunc(x_newtonRaphson);
    while (abs(h) >= EPSILON) {
        h = func(x_newtonRaphson) / derivFunc(x_newtonRaphson);

        x_newtonRaphson = x_newtonRaphson - h;
    }

    return x_newtonRaphson;
}

int main() {
    double x0 = -19.204385;

    double res = newtonRaphson(x0);
    cout << res << endl;   
   
    return 0;
}

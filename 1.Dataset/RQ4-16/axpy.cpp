#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define N 10000000         // vector size
#define A 10.0              // scalar
#define I 20                // # of scaling iterations
#define X 0.00000003e-20    // initial vector value
#define Y 1.00000003        // initial sum value

double a = A;               // can be double
double x[N];                // can be double
double y[N];                // must be double

int main() {
    for (int j=0; j<N; j++) {           // initialize x and y
        x[j] = X;
        y[j] = Y;
    }

    for (int j=0; j<N; j++) {           // compute a*x multiple times
        for (int i=0; i<I; i++) {
            x[j] *= a;
        }
    }

    for (int j=0; j<N; j++) {           // compute x+y
        y[j] += x[j];
    }

    cout << "result: " << std::scientific << std::setprecision(16) << y[0] << endl;

    return 0;
}

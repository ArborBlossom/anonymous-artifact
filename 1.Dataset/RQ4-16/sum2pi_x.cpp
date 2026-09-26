#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

/* macros */
#define ABS(x) ( ((x) < 0.0) ? (-(x)) : (x) )

/* constants */
#define PI     3.1415926535897932384626433832795
#define EPS    5e-7

/* loop  iterations; OUTER is X */
#define INNER    25
#define OUTER    2000

int main() {
    double sum = 0.0;
    double tmp;
    double acc;
    int i, j;

    for (i=0; i<OUTER; i++) {
        acc = 0.0;
        for (j=1; j<INNER; j++) {

            /* accumulatively calculate pi */
            tmp = PI / pow(2.0, j);
            acc = acc + tmp;
        }
        sum = sum + acc;
    }

    cout << "sum " << std::scientific << std::setprecision(16) << sum << endl;

    return 0;
}
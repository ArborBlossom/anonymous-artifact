#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846
#define N 5000

typedef unsigned long int uint_t;

double in_real[N];
double in_imag[N];
double out_real[N];
double out_imag[N];

void dft()
{
    double W_real[N];
    double W_imag[N];
    double arg = 2.0*PI / (double)N;  
                                           
    for (uint_t i = 0; i < N; i++) {  
        W_real[i] =  cos(arg * (double)i);
        W_imag[i] = -sin(arg * (double)i);
    }

    for (uint_t k = 0; k < N; k++) { 
        out_real[k] = in_real[k];  
        out_imag[k] = in_imag[k]; 
        for (uint_t n = 0; n < N; n++) {
            uint_t p = (n * k) % N;
            out_real[k] = out_real[k] + in_real[n] * W_real[p] - in_imag[n] * W_imag[p];
            out_imag[k] = out_imag[k] + in_real[n] * W_imag[p] + in_imag[n] * W_real[p];
        }
    }
}

double sgn(const double x)
{
    double flag;
    if (x>0.0) flag=1;
    else if (x<0.0) flag=-1;
    else flag=0;
    return flag;
}

int main() { 
    for (uint_t i = 0; i < N; i++) {
        double x = ((2.0*PI) / (double)N) * (double)i;
        in_real[i] = sgn(sin(x+1.0))+cos(x);
        in_imag[i] = sgn(cos(x+1.0))+sin(x);
    }

    dft();
    double norm = 0.0;
    
    for (uint_t i = 0; i < N; i++) {
        norm += out_real[i] * out_real[i];
    }
    norm = sqrt(norm);

    cout << "result: " << std::scientific << std::setprecision(16) << norm << endl;

    return 0;
}


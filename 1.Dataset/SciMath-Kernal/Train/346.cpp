#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void cubicSpline(int n, double x[], double y[], double a[], double b[], double c[], double d[]) {
    double h[n];
    double alpha[n];
    double l[n+1];
    double mu[n];
    double z[n+1];
    for (int i = 0; i < n; i++)
        h[i] = x[i+1] - x[i];
    for (int i = 1; i < n; i++)
        alpha[i] = (3.0/h[i])*(y[i+1]-y[i]) - (3.0/h[i-1])*(y[i]-y[i-1]);
    l[0]=1.0; mu[0]=z[0]=0.0;
    for(int i=1;i<n;i++){
        l[i] = 2.0*(x[i+1]-x[i-1]) - h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i]  = (alpha[i] - h[i-1]*z[i-1]) / l[i];
    }
    l[n]=1.0; z[n]=c[n]=0.0;
    for(int j=n-1;j>=0;j--){
        c[j] = z[j] - mu[j]*c[j+1];
        b[j] = (y[j+1]-y[j])/h[j] - h[j]*(c[j+1]+2.0*c[j])/3.0;
        d[j] = (c[j+1] - c[j])/(3.0*h[j]);
        a[j] = y[j];
    }
}

int main() {
    int n = 4;
    double x[] = {0.0,1.0,2.0,3.0};
    double y[] = {0.0,1.0,0.0,1.0};
    double a[4];
    double b[4];
    double c[4];
    double d[4];
    cubicSpline(n-1, x, y, a, b, c, d);
    cout << "d =  " << std::scientific << std::setprecision(16) << d[0] << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void linreg(double x[], double y[], int n, double *m, double *b) {
    double sumx=0.0;
    double sumy=0.0;
    double sumxy=0.0;
    double sumx2=0.0;
    for (int i=0;i<n;i++){
        sumx += x[i]; sumy += y[i];
        sumxy += x[i]*y[i]; sumx2 += x[i]*x[i];
    }
    *m = (n*sumxy - sumx*sumy) / (n*sumx2 - sumx*sumx);
    *b = (sumy - (*m)*sumx) / n;
}

int main() {
    double x[] = {1,2,3,4,5};
    double y[] = {2,2.5,3.5,5,6};
    int n = 5; 
    double m;
    double b;
    linreg(x,y,n,&m,&b);
    cout << "y = mx + b, b = " << std::scientific << std::setprecision(16) << b << endl;
    return 0;
}
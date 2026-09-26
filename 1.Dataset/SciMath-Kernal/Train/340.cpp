#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void linreg(double x[], double y[], int n, double *m) {
    double sumx=0.0;
    double sumy=0.0;
    double sumxy=0.0;
    double sumx2=0.0;
    for (int i=0;i<n;i++){
        sumx += x[i]; sumy += y[i];
        sumxy += x[i]*y[i]; sumx2 += x[i]*x[i];
    }
    *m = (n*sumxy - sumx*sumy) / (n*sumx2 - sumx*sumx);
}

int main() {
    double x[] = {1,2,3,4,5};
    double y[] = {2,2.5,3.5,5,6};
    int n = 5; 
    double m;
    linreg(x,y,n,&m);
    cout << "y = mx + b, m = " << std::scientific << std::setprecision(16) << m << endl;
    return 0;
}
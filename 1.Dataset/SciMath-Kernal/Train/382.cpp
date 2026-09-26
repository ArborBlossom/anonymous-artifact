#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void rSquared(double y[][5], double ypred[][5], int m, int n, double R2[]) {
    for(int i=0;i<m;i++){
        double ssr=0;
        double sst=0;
        double sum=0;
        for(int j=0;j<n;j++) sum+=y[i][j];
        double mean=sum/n;
        for(int j=0;j<n;j++){
            ssr += pow(ypred[i][j]-mean,2);
            sst += pow(y[i][j]-mean,2);
        }
        R2[i]=ssr/sst;
    }
}

int main() {
    double y[1][5] = {{2,3,4,5,6}};
    double ypred[1][5] = {{2.1,2.9,4.2,4.8,6.1}};
    double R2[1];
    rSquared(y,ypred,1,5,R2);
    cout << "R2 = " << std::scientific << std::setprecision(16) << R2[0] << endl;
    return 0;
}
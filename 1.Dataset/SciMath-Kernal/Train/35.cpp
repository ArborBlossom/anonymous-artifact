#include <iostream>
using namespace std;

double slope(double x[], double y[], int n){
    double sx=0;
    double sy=0;
    double sxy=0;
    double sx2=0;
    for(int i=0;i<n;i++){
        sx+=x[i]; sy+=y[i];
        sxy+=x[i]*y[i]; sx2+=x[i]*x[i];
    }
    return (n*sxy - sx*sy)/(n*sx2 - sx*sx);
}

int main(){
    const int n=5;
    double x[n]={1,2,3,4,5};
    double y[n]={2,4,5,4,5};
    slope(x,y,n);
    cout << "Slope: " << std::scientific << std::setprecision(16) << slope(x,y,n) << endl;
    return 0;
}
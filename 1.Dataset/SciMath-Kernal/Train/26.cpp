#include <iostream>
#include <iomanip>
using namespace std;

double f(double xx,double yy){ return xx+yy; }
int main(){
    double x0=0;
    double y0=1;
    double h=0.17;
    double x1=0.53;
    int n=(x1-x0)/h;
    double x=x0;
    double y=y0;
    for(int i=0;i<n;i++){
        y += h*f(x,y);
        x += h;
    }
    cout<<"y("<<x1<<")≈" << std::scientific << std::setprecision(16) << y << endl;
    return 0;
}
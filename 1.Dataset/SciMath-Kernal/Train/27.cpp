#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x){ return log(x); }
double trap(double a,double b,int n){
    double h=(b-a)/n;
    double s=(f(a)+f(b))/2;
    for(int i=1;i<n;i++) s+=f(a+i*h);
    return s*h;
}
int main(){
    trap(1,2,100);
    cout << "∫₁² ln(x)dx ≈ " << std::scientific << std::setprecision(16) << trap(1,2,100) << endl;
    return 0;
}
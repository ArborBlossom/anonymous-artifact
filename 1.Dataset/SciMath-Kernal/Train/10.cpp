#include <iostream>
#include <iomanip>
using namespace std;


double exponential(int n,double x) {
    double sum=1.0;
    for(int i=n-1;i>0;--i)
        sum=1 + x*sum/i;
    return sum;
}
int main(){
    exponential(10,1.0);
    cout << std::scientific << std::setprecision(16) << exponential(10,1.0) << endl;
    return 0;
}

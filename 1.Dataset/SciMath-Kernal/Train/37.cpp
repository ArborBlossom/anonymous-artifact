#include <iostream>
using namespace std;
#include <iomanip> //
#define M_PI       3.14159265358979323846

double domeVolume(double radii[], int n, double h1){
    double sum = 0;
    for(int i=0;i<n;i++) sum += radii[i]*radii[i];
    return (M_PI*h1/3.0)*(sum + radii[0]*radii[n-1]);
}

int main(){
    const int n=4;
    double radii[n]={5.0,4.0,3.0,2.0};
    double h=10.0;
    domeVolume(radii,n,h);
    cout << "Volume: " << std::scientific << std::setprecision(16) << domeVolume(r,n,h) << endl;
    return 0;
}
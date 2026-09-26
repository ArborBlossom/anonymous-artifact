#include <iostream>
#include <iomanip> //
using namespace std;

double movingAvg(double data[], int n, int window){
    double sum=0;
    for(int i=0;i<window;i++) sum+=data[i];
    return sum/window;
}

int main(){
    const int n=5;
    double data[n]={1.0,2.0,3.0,4.0,5.0};
    movingAvg(data,n,3);
    cout << "MA(3): " << std::scientific << std::setprecision(16) << movingAvg(arr,n,3) << endl;
    return 0;
}
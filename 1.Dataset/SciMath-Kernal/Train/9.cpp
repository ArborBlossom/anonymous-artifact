#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    double r=3.7;
    double x=0.5;
    for(int i=0;i<10;i++){
        x = r * x * (1 - x);
        // cout<<x<<" ";
    }
    cout << std::scientific << std::setprecision(16) << x << endl;
    return 0;
}

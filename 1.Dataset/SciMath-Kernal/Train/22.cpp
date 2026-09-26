#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double dist3D(double x1,double y1,double z1,double x2,double y2,double z2){
    return sqrt(pow(x2 - x1,2) + pow(y2 - y1,2) + pow(z2 - z1,2));
}

int main(){
    dist3D(1,2,3,4,6,8);
    cout << "3D distance: " << std::scientific << std::setprecision(16) << dist3D(1,2,3,4,6,8) << endl;
    return 0;
}


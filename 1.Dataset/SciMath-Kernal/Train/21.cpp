#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double dist2D(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
}

int main(){
    dist2D(3,4,7,1);
    cout << "2D distance: " << std::scientific << std::setprecision(16) << dist2D(3,4,7,1) << endl;
    return 0;
}


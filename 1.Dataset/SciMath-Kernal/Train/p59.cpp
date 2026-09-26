#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double s = -55.162905; 
    double q = 86.528059; 
    double p = 89.148722; 
    double t;
    int n = 6;

    for (int i = 0; i < n; ++i) {
        s += q / p;
        t = q;
        q = q + p;
        p = t;
    }
    cout << s; 
   
    return 0;
}

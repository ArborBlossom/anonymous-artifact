#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    const int n = 4;
    double x[n] = {0.0, 1.037, 2.52, 4.036};
    double y[n] = {0.0, 2.03, 3.571, 5.027};
    double length = 0.0;
    for(int i = 1; i < n; ++i) {
        double dx = x[i] - x[i-1];
        double dy = y[i] - y[i-1];
        length += sqrt(dx*dx + dy*dy);
    }
    cout << "Total length: " << std::scientific << std::setprecision(16) << length << endl;
    return 0;
}
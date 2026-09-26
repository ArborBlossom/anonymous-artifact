#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);

double df(double x) {
    return cos(x);
}


double arcLengthTrapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; 
    double arcLength = 0.0; 
    double x;
    double fx1;
    double fx2;

    for (int i = 0; i < n; ++i) {
        x = a + i * h;           
        fx1 = sqrt(1 + df(x) * df(x));       
        fx2 = sqrt(1 + df(x + h) * df(x + h));
        arcLength += (fx1 + fx2) * h / 2;         
    }
    return arcLength;
}

int main() {
    double a = 0.0;  
    double b = PI;   
    int n = 100000;  

    double arcLength1 = arcLengthTrapezoidalRule(a, b, n);
    cout << "result: " << std::scientific << std::setprecision(16) << arcLength1 << endl;

    return 0;
}
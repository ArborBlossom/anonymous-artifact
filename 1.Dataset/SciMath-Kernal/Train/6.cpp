#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double a = 5.3;
    double b = 7.1;
    double h = 3.62;
    double area = ((a + b) / 2.0) * h;
    cout << "Area of Trapezoid: " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}

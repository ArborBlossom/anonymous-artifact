#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double radius = 3.0;
    const double PI = 3.14159265358979323846;
    double area = 4 * PI * radius * radius;
    cout << "Surface Area: " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}
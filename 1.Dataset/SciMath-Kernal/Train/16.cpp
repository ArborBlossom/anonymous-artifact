#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double radius = 2.5;
    double height = 7.0;
    const double PI = 3.14159265358979323846;
    double surface_area = 2 * PI * radius * (radius + height);
    cout << "Surface Area: " << std::scientific << std::setprecision(16) << surface_area << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double radius = 3.0;
    const double PI = 3.14159265358979323846;
    double volume = (2.0/3.0) * PI * radius * radius * radius;
    cout << "Volume: " << std::scientific << std::setprecision(16) << volume << endl;
    return 0;
}
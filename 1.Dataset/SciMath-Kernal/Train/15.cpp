#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double radius = 2.5;
    double height = 7.0;
    const double PI = 3.14159265358979323846;
    double volume = PI * radius * radius * height;
    cout << "Volume: " << std::scientific << std::setprecision(16) << volume << endl;
    return 0;
}
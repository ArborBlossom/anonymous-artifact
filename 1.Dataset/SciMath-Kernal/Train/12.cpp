#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    double radius = 5.0;
    const double PI = 3.14159265358979323846;
    double circumference = 2 * PI * radius;
    cout << "Circumference: " << std::scientific << std::setprecision(16) << circumference << endl;
    return 0;
}
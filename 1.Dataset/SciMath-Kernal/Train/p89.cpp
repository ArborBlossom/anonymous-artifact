#include <iostream>
using namespace std;


int main() {
    double height = -83.781867;
    double width = 21.360558;
    double length = 99.545570;
    double radius = -71.882651;


    double volume = length * width * height;
    double areaBox = 2 * (length * width + length * height + height * width);
    double areaCircle = 3.14 * (radius * radius);

    cout << areaCircle << endl;  

    return 0;
}

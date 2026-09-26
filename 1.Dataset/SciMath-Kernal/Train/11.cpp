#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    double weight = 70.5; // kg
    double height = 1.75; // m
    double bmi = weight / (height * height);
    cout << "BMI: " << std::scientific << std::setprecision(16) << bmi << endl;
    return 0;
}
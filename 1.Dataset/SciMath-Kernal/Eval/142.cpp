#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double V = 12.0;    
    double I = 0.5;     
    double R = V / I;   
    cout << "电阻: " << std::scientific << std::setprecision(16) << R << endl;
    return 0;
}
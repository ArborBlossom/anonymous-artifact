#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
using namespace std;

int num_iterations = 1000000;  

double sinePerf() {
    double total = 0.0;  
    num_iterations=1000000;
    for (int i = 0; i < num_iterations; ++i) {
        double x;
        double result ;
        x = i * 0.0001;  
        result= sin(x);  
        total = total+result;  
    }

    return total;
}



int main() {
    sinePerf();
    cout << "sum " << std::scientific << std::setprecision(16) << sinePerf() << endl;

    return 0;
}
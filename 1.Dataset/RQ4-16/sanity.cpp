#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

double p = 1.00000003;     
double l = 0.00000003;      
double o;

int main()
{
    o = p + l;
    cout << "result: " << std::scientific << std::setprecision(16) << o << endl;

    return 0;
}

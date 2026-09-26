#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double determinant3x3(double m[3][3]) {
    return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])
         - m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0])
         + m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
}

int main() {
    double m[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    double det = determinant3x3(m);
    cout << "矩阵行列式 = " << std::scientific << std::setprecision(16) << det << endl;
    return 0;
}
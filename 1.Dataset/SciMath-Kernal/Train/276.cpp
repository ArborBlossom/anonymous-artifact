#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double determinant3(double A[3][3]) {
    return A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
         - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
         + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
}
double determinant33(double M[3][3]) {
    return M[0][0]*(M[1][1]*M[2][2]-M[1][2]*M[2][1])
         - M[0][1]*(M[1][0]*M[2][2]-M[1][2]*M[2][0])
         + M[0][2]*(M[1][0]*M[2][1]-M[1][1]*M[2][0]);
}

void cramersRule(double A[3][3], double B[3], double X[3]) {
    double D = determinant3(A);
    double M[3][3];
    for (int i = 0; i < 3; i++) {
        // 构造替换矩阵
        for (int r = 0; r < 3; r++) for (int c = 0; c < 3; c++)
            M[r][c] = (c==i ? B[r] : A[r][c]);
        X[i] = determinant33(M) / D;
    }
}

int main() {
    double A[3][3] = {{2.0, -1.0, 3.0}, {1.0, 0.0, -2.0}, {3.0, 1.0, 1.0}};
    double B[3] = {5.0, -4.0, 6.0};
    double X[3];
    cramersRule(A, B, X);
    cout << "方程组解：x = " << std::scientific << std::setprecision(16) << X[0] << endl;
    return 0;
}
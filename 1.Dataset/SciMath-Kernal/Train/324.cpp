#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double det(double A[][4], int n) {
    if (n == 1) return A[0][0];
    double D = 0.0;
    double temp[4][4];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        int ti = 0;
        for (int i = 1; i < n; i++) {
            int tj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                temp[ti][tj++] = A[i][j];
            }
            ti++;
        }
        D += sign * A[0][f] * det(temp, n-1);
        sign = -sign;
    }
    return D;
}

int main() {
    double A[4][4] = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {2.0, 6.0, 4.0, 8.0},
        {3.0, 1.0, 1.0, 2.0}
    };
    det(A, 4);
    cout << "Determinant = " << std::scientific << std::setprecision(16) << det(A, 4) << endl;
    return 0;
}
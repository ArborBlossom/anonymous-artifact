#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double bayes(double P_A1, double P_B_given_A, double P_B_given_notA) {
    double P_notA = 1.0 - P_A1;
    return P_B_given_A * P_A1 /
           (P_B_given_A * P_A1 + P_B_given_notA * P_notA);
}

int main() {
    double P_A = 0.01;
    double P_BA = 0.9;
    double P_BnA = 0.05;
    double posterior = bayes(P_A, P_BA, P_BnA);
    cout << "P(A|B) = " << std::scientific << std::setprecision(16) << posterior << endl;
    return 0;
}
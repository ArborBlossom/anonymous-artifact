#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void movingStd(double data[], int n, int w, double std[]) {
    for (int i = 0; i <= n-w; i++) {
        double sum=0.0;
        double sum2=0.0;
        for (int j = 0; j < w; j++) {
            sum  += data[i+j];
            sum2 += data[i+j]*data[i+j];
        }
        double mean = sum / w;
        std[i] = sqrt(sum2/w - mean*mean);
    }
}

int main() {
    double data[] = {1.0,2.0,3.0,4.0,5.0};
    int n = sizeof(data)/sizeof(data[0]);
    int w = 3;
    double std[3];
    movingStd(data,n,w,std);
    cout << "Std at window i = " << std::scientific << std::setprecision(16) << std[1] << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
    int i;
    int n = 5;
    double y = 88.006818; // 原值: 0.5
    double z = -52.670372; // 原值: 0.3
    cin >> y >> z;

    double answer = 0;
    for (i = 0; i < n; i++)
        answer += y * pow(z, i);

    cout << answer;
 
    return 0;
}

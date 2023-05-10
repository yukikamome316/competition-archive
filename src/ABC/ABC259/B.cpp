#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    double rad = (double)d / 180.0 * M_PI;
    cout << std::fixed
        << std::setprecision(15)
        << a * cos(rad) - b * sin(rad) 
        << " "
        << a * sin(rad) + b * cos(rad) 
        << endl;
}
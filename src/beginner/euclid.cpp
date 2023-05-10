#include <bits/stdc++.h>
using namespace std;

int euclid(int x, int y) {
   /* 
    * a = bq + r において, gcd(a, b) = gcd(b, r)
    * r = a mod b 
    * 
    * cf.)
    * gcd(18, 14)
    * = gcd(14, 4)
    * = gcd(4, 2)
    * = gcd(2, 2)
    * = gcd(2, 0)
    * = 2
    *
    * 18 = 14 * 1 + 4
    * 14 = 4 * 3 + 2
    * 4 = 2 * 2
    */

    return (y == 0) ? x : euclid(y, x % y);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << euclid(a, b) << endl;
    return 0;
}
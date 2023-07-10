#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  while (true) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c + d == 0) break;
    cout << __gcd(a, __gcd(b, __gcd(c, d))) << endl;
  }
}
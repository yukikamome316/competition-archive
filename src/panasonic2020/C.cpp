#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  bool ok = false;
  if (c - b - a >= 0) {
    ok = 4 * a * b < (c - b - a)*(c - b - a);
  }
  
  cout << (ok ? "Yes" : "No") << endl; 
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  
  int cnt = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    if (cnt >= 10000000) break;
    int na = 0, nb = 0, nc = 0;
    int ha = A / 2, hb = B / 2, hc = C / 2;
    A = hb + hc;
    B = ha + hc;
    C = ha + hb;
    cnt++;
  }
  cout << (cnt != 10000000 ? cnt : -1) << endl;
}
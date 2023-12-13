#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

long long pow(long long x, long long n, long long MOD) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int A_mod = A % 10;
  // 周期を求める
  vector<int> cycle(4);
  rep(i, 4) {
    cycle[i] = A_mod % 10;
    A_mod *= (A % 10);
  }

  cout << cycle[(pow(B, C, 4) + 3) % 4] << endl;
}
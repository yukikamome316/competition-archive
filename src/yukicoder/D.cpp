#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    ll N, X;
    cin >> N >> X;
    if (N * (N + 1) / 2 > X) {
      cout << -1 << endl;
      continue;
    }
    
    rep(i, N - 1) {
      cout << i + 1 << " ";
    }
    cout << N + X - N * (N + 1) / 2 << endl;
  }
}
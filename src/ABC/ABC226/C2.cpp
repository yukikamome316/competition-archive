#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  vector<int> T(N);
  rep(i, N) {
    int T_tmp, K;
    cin >> T_tmp >> K;
    T[i] = T_tmp;
    
    rep(j, K) {
      int A;
      cin >> A;
      A--;
      G[i].push_back(A);
    }
  }

  vector<bool> seen(N);
  ll ans = 0;

  seen[N - 1] = true;
  for (int i = N - 1; i >= 0; i--) {
    if (seen[i]) {
      ans += T[i];
      for (auto e : G[i]) {
        seen[e] = true;
      }
    }
  }

  cout << ans << endl;
}
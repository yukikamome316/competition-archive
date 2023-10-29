#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using mint = modint998244353;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  vector<mint> dp(N + 1);
  dp[0] = 0;
  rep(i, N + 1) {
    rep(j, i + 1) {
      dp[i] = dp[j + 1] + A[i];
    }
    dp[i] /= N;
  }

  cout << dp[N].val() << endl;
}
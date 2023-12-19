#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N + 1), v(N + 1);
  rep(i, N) {
    cin >> w[i + 1] >> v[i + 1];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -1e16));
  rep(i, N + 1) dp[0][i] = 0;
  
  rep2(i, 1, N + 1) {
    rep2(j, 1, W + 1) {
      dp[i][j] = dp[i - 1][j];
      if (j - w[i] >= 0) chmax(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }

  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}

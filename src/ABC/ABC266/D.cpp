#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  // dp[i][j]: 時刻iに座標jにいるときの最大値
  // dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1])
  //            + (i == t[k] かつ x[k] == j となる k に対する a[k])

  constexpr int maxTime = 100000;

  int n;
  cin >> n;
  vector<int> x(maxTime + 1, 0), a(maxTime + 1, 0);

  rep(i, n) {
    int t_tmp, x_tmp, a_tmp;
    cin >> t_tmp >> x_tmp >> a_tmp;

    x[t_tmp] = x_tmp;
    a[t_tmp] = a_tmp;
  }

  vector dp(maxTime + 10, vector<ll>(5, 0));
  rep2(i, 1, 5) { dp[0][i] = -1e18; }

  rep2(t, 1, maxTime + 1) {
    rep(i, 5) {
      dp[t][i] = dp[t - 1][i];

      if (i != 4) {
        chmax(dp[t][i], dp[t - 1][i + 1]);
      }
      if (i != 0) {
        chmax(dp[t][i], dp[t - 1][i - 1]);
      }
    }
    dp[t][x[t]] += a[t];
  }

  ll ans = 0;
  rep(i, 5) { chmax(ans, dp[maxTime][i]); }

  cout << ans << endl;
}

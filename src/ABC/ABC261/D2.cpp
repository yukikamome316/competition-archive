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
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  vector<int> y(n + 1);

  rep(i, n) { cin >> x[i]; }
  rep(i, m) {
    int c;
    cin >> c;
    cin >> y[c];
  }

  // dp[i][j] := i回目の時点でカウンタがjの時にとりうる最大金額
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));

  dp[0][0] = 0;

  // 貰うDPを実装したほうが楽
  rep2(i, 1, n + 1) {
    rep(j, n + 1) { chmax(dp[i][j], dp[i - 1][j - 1] + x[i - 1] + y[j]); }
    dp[i][0] = 0;
    rep(j, i) { chmax(dp[i][0], dp[i - 1][j]); }
  }

  cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}

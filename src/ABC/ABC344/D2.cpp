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
  string t;
  int n;
  cin >> t >> n;

  vector s(n, vector<string>());
  rep(i, n) {
    int a;
    cin >> a;
    s[i].resize(a);

    rep(j, a) { cin >> s[i][j]; }
  }

  // dp[i][j]: 袋iまで見て、tの接頭辞のうちj文字目まで一致している場合の最小金額
  vector dp(n + 1, vector<int>(t.size() + 1, 1e9));
  dp[0][0] = 0;

  rep2(i, 1, n + 1) {
    rep(j, t.size() + 1) {
      // 袋iから文字列を選ばない場合
      chmin(dp[i][j], dp[i - 1][j]);
      rep(k, s[i - 1].size()) {
        if (j + s[i - 1][k].size() <= t.size() &&
            t.substr(j, s[i - 1][k].size()) == s[i - 1][k]) {
          // sがtの接頭辞となるすべての場合について、コストを計算して最小値を求める
          chmin(dp[i][j + s[i - 1][k].size()], dp[i - 1][j] + 1);
        }
      }
    }
  }

  int ans = dp[n][t.size()];
  cout << (ans != 1e9 ? ans : -1) << endl;
}

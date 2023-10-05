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
  vector<int> s(N);
  rep(i, N) cin >> s[i];

  vector<vector<bool>> dp(N + 1, vector<bool>(100 * 100 + 1));
  // dp[i][j]: i個目までを使ってj点を作れるか
  
  dp[0][0] = true;

  rep(i, N) {
    rep(j, 100 * 100 + 1) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;      
        dp[i + 1][j + s[i]] = true;
      }
    }
  }

  int ans = 0;
  rep(i, 100 * 100 + 1) {
    if (i % 10 != 0 && dp[N][i]) chmax(ans, i);
  }
  
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, n) { cin >> t[i]; }

  // dp[i][j]: i個目までのレシピまで見て和をjにできるか？ (部分和問題)
  vector dp(n + 1, vector<int>(100001, 0));

  dp[0][0] = 1;

  rep(i, n) {
    rep(j, 100001) {
      dp[i + 1][j] |= dp[i][j];
      if (j - t[i] >= 0) {
        dp[i + 1][j] |= dp[i][j - t[i]];
      }
    }
  }

  int sum = accumulate(t.begin(), t.end(), 0);

  int min_val = 1e9;
  rep2(i, (sum + 2 - 1) / 2, sum + 1) {
    if (dp[n][i] && i < min_val) {
      min_val = i;
    }
  }

  cout << min_val << endl;
}

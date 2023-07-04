#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string x, y;
  cin >> x >> y;

  vector dp(x.size() + 1, vector<ll>(y.size() + 1, 0));
  rep(i, x.size() + 1) {
    dp[i][0] = i;
  }  
  rep(i, y.size() + 1) {
    dp[0][i] = i;
  }

  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < y.size(); j++) {
      int diff = x[i] != y[j];

      dp[i + 1][j + 1] = min({dp[i][j] + diff, dp[i + 1][j] + 1, dp[i][j + 1] + 1});
    }
  }

  cout << dp[x.size()][y.size()] << endl;
  
}
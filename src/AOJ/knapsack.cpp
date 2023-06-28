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
  vector<pair<int, int>> data(N);
  rep(i, N) {
    int v, w;
    cin >> v >> w;
    data[i] = {v, w};
  }

  vector dp(N, vector<ll>(W + 1, -1));
  
  dp[0][0] = 0;
  dp[0][data[0].second] = data[0].first;

  rep2(i, 1, N) {
    rep(j, W + 1) {
      if (j - data[i].second >= 0) {
        dp[i][j] = max(dp[i - 1][j - data[i].second] + data[i].first, dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << *max_element(dp[N - 1].begin(), dp[N - 1].end()) << endl;

}
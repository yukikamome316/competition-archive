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

  ll value_sum = 0;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    value_sum += y;
    data[i] = {x, y};
  }


  vector dp(N + 1, vector<ll>(value_sum + 1, 2e9));
  rep(i, N + 1) {
    dp[i][0] = 0;
  }

  rep(i, N) {
    rep(j, value_sum + 1) {
      chmin(dp[i + 1][j], dp[i][j]);
      if (j + data[i].second <= value_sum) {
        chmin(dp[i + 1][j + data[i].second], dp[i][j] + data[i].first);
      }
    }
  }

  while (value_sum >= 0) {
    if (dp[N][value_sum] <= W) {
      cout << value_sum << endl;
      return 0;
    }
    value_sum--;
  }
}
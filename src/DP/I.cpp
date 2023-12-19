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
  vector<double> p(N);
  rep(i, N) cin >> p[i];

  vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
  dp[0][0] = 1.0;

  rep2(i, 1, N + 1) { 
    rep(j, N + 1) {
      dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1.0 - p[i - 1]) * dp[i - 1][j];
    }
  }

  double ans = 0.0;
  rep2(i, N / 2 + 1, N + 1) ans += dp[N][i];
  cout << setprecision(10) << ans << endl;
}

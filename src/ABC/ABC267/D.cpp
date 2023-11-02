#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
  dp[0][0] = 0;
  dp[0][1] = LONG_LONG_MIN;

  rep2(i, 1, N + 1) {
    rep(j, N + 1) {
      if (j == 0) dp[i][j] = 0;
      else if (j > i) dp[i][j] = LONG_LONG_MIN;
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + j * A[i - 1]);
    }
  }

  cout << dp[N][M] << endl;
}

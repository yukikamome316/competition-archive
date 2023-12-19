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
  vector h(N, vector<int>(3));
  rep(i, N) {
    rep(j, 3) {
      cin >> h[i][j];
    }
  }
  
  vector dp(N + 1, vector<int>(3, -2e9));
  rep(i, 3) dp[0][i] = 0;

  rep2(i, 1, N + 1) {
    rep(j, 3) {
      dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + h[i - 1][j];
    }
  }
  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}

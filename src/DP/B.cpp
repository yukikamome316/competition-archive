#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  rep(i, N) cin >> h[i];

  vector<int> dp(N + 1, 2e9);
  dp[0] = 0;

  rep2(i, 1, N) {
    rep2(j, 1, K + 1) {
      if (i - j >= 0)
        chmin(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  
  cout << dp[N - 1] << endl;
}

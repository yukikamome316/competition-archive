#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string s, t;
  cin >> s >> t;

  vector dp(s.size() + 1, vector<ll>(t.size() + 1));
  vector dp_prev(s.size() + 1, vector<pair<int, int>>(t.size() + 1));

  for (int i = 1; i < s.size() + 1; i++) {
    for (int j = 1; j < t.size() + 1; j++) {
      dp[i][j] = dp[i - 1][j];
      dp_prev[i][j] = {i - 1, j};

      if (dp[i][j] < dp[i][j - 1]) {
        dp[i][j] = dp[i][j - 1];
        dp_prev[i][j] = {i, j - 1};
      }

      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        dp_prev[i][j] = {i - 1, j - 1};
      }
    }
  }
  

}
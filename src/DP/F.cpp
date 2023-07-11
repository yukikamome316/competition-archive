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
  vector dp_prev(s.size() + 1, vector<pair<int, int>>(t.size() + 1, {-1, -1}));

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

  if (dp[s.size()][t.size()] == 0) {
    cout << endl;
    return 0;
  }

  pair<int, int> current = {s.size(), t.size()};
  string result;

  while (current.first != 0 && current.second != 0) {
    if (s[current.first - 1] == t[current.second - 1]) {
      result.insert(result.begin(), s[current.first - 1]);
    }
    current = dp_prev[current.first][current.second];
  }

  cout << result << endl;
}
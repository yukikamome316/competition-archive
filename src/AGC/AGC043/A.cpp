// 経路を固定して考えてみる

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> fi(H);
  rep(i, H)
    cin >> fi[i];

  vector dp(H, vector<int>(W, 2e9));
  dp[0][0] = (fi[0][0] == '#');

  vector<int> dx = {0, 1};
  vector<int> dy = {1, 0};

  rep(i, H) {
    rep(j, W) {
      rep(dir, 2) {
        int nx = i + dx[dir], ny = j + dy[dir];
        if (nx >= H || ny >= W) continue;

        chmin(dp[nx][ny], dp[i][j] + (fi[i][j] == '.' && fi[nx][ny] == '#'));
      }
    }
  }

  cout << dp[H - 1][W - 1] << endl;
}
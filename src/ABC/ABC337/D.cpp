#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  int ans = 2e9;
  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] == 'x') continue;
      
      queue<pair<int, int>> que;
      que.push({i, j});
      int cnt = 0;
      while (!que.empty()) {
        auto [y, x] = que.front();
        que.pop();
        if (y < 0 || y >= H || x < 0 || x >= W) continue;
        if (grid[y][x] == 'x') continue;
        if (gird[y][x] == '.') cnt++;
        if (cnt == K) break;
        que.push({y+1, x});
        que.push({y-1, x});
      }

    }
  }

  if (ans == 2e9) ans = -1;
  cout << ans << endl;
}

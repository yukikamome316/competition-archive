#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int H, W;

inline bool isValidPos(pair<int, int> pos) {
  auto [x, y] = pos;
  return (x >= 0 && y >= 0 && x < H && y < W);
}

int main() {
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};

  vector step(H, vector<int>(W, -1));
  queue<pair<int, int>> que;

  que.push({0, 0});
  step[0][0] = 0;

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == H - 1 && y == W - 1) break;

    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (isValidPos({nx, ny}) && step[nx][ny] == -1 && grid[nx][ny] == '.') {
        que.push({nx, ny});
        step[nx][ny] = step[x][y] + 1;
      }
    }
  }

  int cnt = 0;
  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] == '.') cnt++;
    }
  }

  if (step[H - 1][W - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << cnt - step[H - 1][W - 1]  - 1 << endl;
  }
}

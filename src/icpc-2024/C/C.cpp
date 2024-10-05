#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(2001, vector<int>(2001, -1));
  queue<pair<int, int>> q;
  q.push({1000, 1000});
  int dx[] = {0, 1, 1, 0, -1, -1};
  int dy[] = {1, 0, -1, -1, 0, 1};
  d[1000][1000] = 0;
  while (q.size()) {

    auto p = q.front(); q.pop();
    for (int i = 0; i < 6; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (nx > 2000 or nx < 0 or ny < 0 or ny > 2000) continue;
      if (d[nx][ny] != -1) continue;
      d[nx][ny] = d[p.first][p.second] + 1;
      q.push({nx, ny}); 
    }
  }


  rep(i, n) {
    int gx, gy;
    cin >> gx >> gy;
    gx += 1000;
    gy += 1000;
    cout << d[gx][gy] << endl;
  }
}

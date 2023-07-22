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
  vector<string> fi(N);
  rep(i, N) cin >> fi[i];

  vector<vector<bool>> seen(N, vector<bool>(M, false));
  queue<pair<int, int>> que;
  que.push({1, 1});
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    if (fi[x][y] == '#' || seen[x][y]) continue;
    seen[x][y] = true;
    if (fi[x][y - 1] == '#' && fi[x + 1][y] == '#') {
      que.push({x, y + 1});
      que.push({-1, 0});
    }
    if (fi[x + 1][y] == '#' && fi[x][y + 1] == '#') {
      
    }
  }

}
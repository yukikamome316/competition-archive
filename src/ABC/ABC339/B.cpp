#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<string> grid(H);
  string S;
  rep(i, W) S += '.';
  rep(i, H) grid[i] = S;

  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  int cur = 0;
  int nx = 0, ny = 0;
  rep(i, N) {
    if (grid[nx][ny] == '.') {
      grid[nx][ny] = '#';
      cur = (cur + 1) % 4;
      nx = (nx + dx[cur] + H) % H; // Apply torus topology to nx
      ny = (ny + dy[cur] + W) % W; // Apply torus topology to ny
      
    } else {
      grid[nx][ny] = '.';
      cur = (cur + 3) % 4;
      nx = (nx + dx[cur] + H) % H; // Apply torus topology to nx
      ny = (ny + dy[cur] + W) % W; // Apply torus topology to ny
    }
  }

  rep(i, H) cout << grid[i] << endl;
}

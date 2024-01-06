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
  vector<vector<int>> grid(N, vector<int>(N));
  int num = 1;
  int x = 0, y = 0;
  int dx = 0, dy = 1;
  for (int i = 0; i < N * N; i++) {
    grid[x][y] = num++;
    if (x + dx >= N || x + dx < 0 || y + dy >= N || y + dy < 0 || grid[x + dx][y + dy] != 0) {
      int temp = dx;
      dx = dy;
      dy = -temp;
    }
    x += dx;
    y += dy;
  }
  grid[N / 2][N / 2] = -1;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == -1) cout << 'T' << " ";
      else cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

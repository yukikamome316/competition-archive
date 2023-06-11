#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H)
    cin >> grid[i];

  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] == '.') {
        int cnt = 0;
        if (i > 0 && grid[i - 1][j] == '#') cnt++;
        if (i < H - 1 && grid[i + 1][j] == '#') cnt++;
        if (j > 0 && grid[i][j - 1] == '#') cnt++;
        if (j < W - 1 && grid[i][j + 1] == '#') cnt++;

        if (cnt >= 2) {
          cout << i + 1 << " " << j + 1 << endl;
          return 0;
        }
      }
    }
  }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> fi(H);
  rep(i, H)
    cin >> fi[i];

  vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
  vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};

  rep(i, H) {
    rep(j, W) {
      if (fi[i][j] == '#') continue;
      int cnt = 0;
      rep(dir, 8) {
        int nx = i + dx[dir], ny = j + dy[dir];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && fi[nx][ny] == '#') {
          cnt++;
        }
      }
      fi[i][j] = cnt + '0';
    }
  }

  rep(i, H) {
    cout << fi[i] << endl;
  }
}
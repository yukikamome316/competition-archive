#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w + h == 0) break;

    vector<vector<int>> fi(h, vector<int>(w, 0));
    rep(i, w + h - 1) {
      int x, y, n;
      cin >> x >> y >> n;
      fi[x - 1][y - 1] = 1;
    }

    vector<int> x(h, 0);
    vector<int> y(w, 0);

    y[0] = 1;
    bool finished = false;
    bool vertical = true;
    while (!finished) {
      if (vertical) {
        rep(i, w) {
          bool cnt = false;
          if (!y[i]) continue;
          rep(j, h) {
            if (fi[j][i]) {
              if (x[j]) continue;
              x[j] = 1;
              cnt = true;
            }
          }
          if (!cnt) finished = true;
        }
      } else {
        rep(i, h) {
          if (!x[i]) continue;
          bool cnt = false;
          rep(j, w) {
            if (fi[i][j]) {
              if (y[j]) continue;
              y[j] = 1;
              cnt = true;
            }
          }
          if (!cnt) finished = true;
        }
      }

      vertical ^= 1;
    }

    bool ok = true;
    rep(i, h) {
      ok = (x[i] == 1);
    }
    rep(i, w) {
      ok = (y[i] == 1);
    }

    cout << (ok ? "YES" : "NO") << endl;
  }
}
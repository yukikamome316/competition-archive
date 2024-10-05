#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void printGrid(deque<deque<int>> grid) {
  rep(i, grid.size()) {
    rep(j, grid[0].size()) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  while (true) {
    int n, m, t, p;
    cin >> n >> m >> t >> p;
    if (n == 0
      && m == 0
      && t == 0
      && p == 0) break;

    deque grid(n, deque<int>(m, 1));

    rep(i, t) {
      int d, c;
      cin >> d >> c;
      assert(d == 1 || d == 2);
      assert(c > 0);

      if (d == 1) {
        if (c > m / 2) {
          rep(i, n) {
            rep(j, m - c - 1) {
              grid[i].push_back(0);
            }
          }
          // Debug
          printGrid(grid);
        }
        rep(i, n) {
          rep(j, c) {
            grid[i][j]--;
            grid[i][c - j + 2]++;
            printGrid(grid);
          }
        }

        rep(i, n) {
          rep(j, c) {
            grid[i].pop_front();
          }
        }

        printGrid(grid);
        
      } else if (d == 2) {
        if (c > n / 2) {
          rep(i, n - c - 1) {
            deque<int> empty_row(grid[0].size());
            grid.push_back(empty_row);
          }
          // Debug
          printGrid(grid);
          offset = n - c;
        }

        rep(i, c) {
          rep(j, m) {
            grid[n - i - 1][j]--;
            grid[(n - i - 1) + c][j]++;
          }
        }
      }
    }

    ll hole_cnt = 0;
    rep(i, p) {
      int x, y;
      cin >> x >> y;
      assert(x >= 0 && y >= 0);

      hole_cnt += grid[y][x];
    }

    cout << hole_cnt << endl;
  }
}

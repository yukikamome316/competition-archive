#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return 1;} return 0;}
using ll = long long;
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    set<int> students;
    vector<vector<int>> fi(n, vector<int>(n));
    rep(i, n) {
      rep(j, n) {
        int tmp;
        cin >> tmp;
        fi[i][j] = tmp;
        students.insert(tmp);
      }
    }

    int cnt = 0;
    while (cnt <= 100000) {
      map<int, vector<int>> next;
      vector<int> dx = {1, 0, -1, 0};
      vector<int> dy = {0, 1, 0, -1};
      rep(i, n) {
        rep(j, n) {
          rep(dir, 4) {
            int nx = i + dx[dir], ny = j + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            next[fi[i][j]].push_back(fi[nx][ny]);
          }
        }
      }

      for (auto&& [key, val] : next) {
        sort(val.begin(), val.end());
      }

      for (int x : students) {
        pair<int, int> x_pos;
        rep(i, n) {
          rep(j, n) {
            if (fi[i][j] == x) {
              x_pos.first = i;
              x_pos.second = j;
            }
          }
        }

        vector<int> next_to_x = next[x];
        set<pair<int, int>> ng_pos;
        ng_pos.insert(x_pos);

        for (int y : next_to_x) {
          rep(i, n) {
            rep(j, n) {
              if (fi[i][j] == y) {
                rep(dir, 4) {
                  int nx = i + dx[dir], ny = j + dy[dir];
                  if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                  ng_pos.insert({nx, ny});
                }
              }
            }
          }
        }

        int max_distance = -2e9;
        pair<int, int> max_pos;
        rep(i, n) {
          rep(j, n) {
            bool ok = true;
            for (pair<int, int> x : ng_pos) {
              if (x.first == i && x.second == j) ok = false;
            }
            if (!ok) continue;

            int dist = abs(i - x_pos.first) + abs(j - x_pos.second);
            if (max_distance < dist && dist >= n / 2) {
              max_distance = dist;
              max_pos = {i, j};
            }
          }
        }

        swap(fi[x_pos.first][x_pos.second], fi[max_pos.first][max_pos.second]);
      }
      cnt++;
    }

    rep(i, n) {
      rep(j, n) {
        cout << fi[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}

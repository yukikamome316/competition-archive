#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int gx, gy;
    cin >> gx >> gy;
    pair<int, int> gpos = {gx, gy};

    vector<vector<pair<int, int>>> object_pos;
    int obj_cnt;
    cin >> obj_cnt;
    rep(i, obj_cnt) {
      int x1, x2, y1, y2;
      cin >> x1 >> x2 >> y1 >> y2;
      object_pos.push_back({{x1, x2}, {y1, y2}});
    }

    auto connectable = [&](pair<int, int> x, pair<int, int> y) {
      bool found = false;
      for (vector pos2 : object_pos) {
        found = (pos2[0] == x && pos2[1] == y) || (pos2[1] == x && pos2[0] == y);
        if (found) break;
      }
      return !found;
    };
    
    ll dp[gx + 1][gy + 1];
    dp[0][0] = 1;
    rep(i, gx + 1) {
      rep(j, gy + 1) {
        if (i > 0 && j > 0) {
          dp[i][j] = connectable({i, j}, {i - 1, j}) ? dp[i - 1][j] : 0;
          dp[i][j] += connectable({i, j}, {i, j - 1}) ? dp[i][j - 1] : 0;
        }
        else if (i > 0) dp[i][j] = connectable({i, j}, {i - 1, j}) ? dp[i - 1][j] : 0;
        else if (j > 0) dp[i][j] = connectable({i, j}, {i, j - 1}) ? dp[i][j - 1] : 0;
      }
    }
    if (dp[gx][gy] > 0) {
      cout << dp[gx][gy] << endl;
    } else {
      cout << "Miserable Hokusai!" << endl;
    }
  }
}
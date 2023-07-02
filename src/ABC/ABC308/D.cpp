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

  string snuke = "snuke";
  queue<pair<int, int>> q;
  vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
  vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};

  q.push({0, 0});
  while (!q.empty()) {
    auto x = q.top();
    q.pop();

    rep(i, 8) {
      int nx = x.first + dx[i], xy = x.second;

    }
  }
}
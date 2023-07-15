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
  vector<int> t(N + 1);
  vector<pair<int, int>> pos(N + 1, {0, 0});
  rep(i, N) {
    int x, y;
    cin >> t[i + 1] >> x >> y;
    pos[i + 1] = make_pair(x, y);
  }

  rep(i, N) {
    int dist = abs(pos[i + 1].first - pos[i].first) + abs(pos[i + 1].second - pos[i].second);
    if (dist > t[i + 1] - t[i] || (t[i + 1] - t[i] - dist) % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
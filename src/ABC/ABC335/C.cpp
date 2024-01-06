#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  deque<pair<int, int>> dq;
  rep(i, N) {
    dq.push_back({i + 1, 0});
  }
  rep(_, Q) {
    int x;
    cin >> x;
    if (x == 1) {
      char y;
      cin >> y;
      auto prev = dq.front();
      dq.pop_back();

      if (y == 'R') {
        dq.push_front({prev.first + 1, prev.second});
      } else if (y == 'L') {
        dq.push_front({prev.first - 1, prev.second});
      } else if (y == 'U') {
        dq.push_front({prev.first, prev.second + 1});
      } else if (y == 'D') {
        dq.push_front({prev.first, prev.second - 1});
      }
    } else if (x == 2) {
      int y;
      cin >> y;
      auto current = dq.begin() + y - 1;
      cout << current->first << " " << current->second << endl;
    }
  }
}

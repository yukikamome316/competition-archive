#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

class Vec2 {
public:
  int x, y;
  
  Vec2() : x(0), y(0) {};
  Vec2(int x, int y) : x(x), y(y) {};
};

int main() {
  while (true) {
    int h, w;
    cin >> h >> w;
    if (h == 0 && w == 0) break;

    map<int, Vec2> keyboard;
    rep(i, h) {
      string s;
      cin >> s;
      rep(j, w) {
        keyboard[s[j]] = Vec2(i, j);
      }
    }

    string target;
    cin >> target;

    Vec2 src = Vec2(0, 0);
    ll cnt = 0;

    rep(i, target.size()) {
      Vec2 dest = keyboard[target[i]];
      ll diff_x = abs(dest.x - src.x);
      ll diff_y = abs(dest.y - src.y);
      cnt += diff_x + diff_y + 1;
      src = dest;
    }

    cout << cnt << endl;
  }
}

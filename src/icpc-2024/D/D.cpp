#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

enum class eDirection { RIGHT, UP, LEFT, DOWN };

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    int a, b;
    ll d;
    cin >> a >> b >> d;

    set<pair<int, int>> obs;
    rep(i, n) {
      int x, y;
      cin >> x >> y;
      obs.insert(make_pair(x, y));
    }

    pair<ll, ll> pos = make_pair(a, b);
    eDirection dir = eDirection::RIGHT;

    while (d > 0) {
        if (dir == eDirection::RIGHT) {
        bool found = false;
        rep(i, max(100ll - pos.first, 0ll)) {
          auto tPos = make_pair(pos.first + i + 1, pos.second);
          if (!obs.contains(tPos)) continue;

          found = true;
          tPos.first--;
          d -= min(abs(tPos.first - pos.first), d);
          pos = tPos;
          dir = eDirection::UP;
          break;
        }

        if (!found) {
          pos.first += d;
          d = 0;
        }
      } else if (dir == eDirection::UP) {
        bool found = false;
        rep(i, 100) {
          auto tPos = make_pair(pos.first, pos.second + i + 1);
          if (!obs.contains(tPos)) continue;

          found = true;
          tPos.second--;
          d -= abs(tPos.second - pos.second);
          pos = tPos;
          dir = eDirection::LEFT;
          break;
        }

        if (!found) {
          pos.second += d;
          d = 0;
        }
      } else if (dir == eDirection::LEFT) {
        bool found = false;
        rep(i, 100) {
          auto tPos = make_pair(pos.first - i - 1, pos.second);
          if (!obs.contains(tPos)) continue;

          found = true;
          tPos.first++;
          d -= abs(tPos.first - pos.first);
          pos = tPos;
          dir = eDirection::DOWN;
          break;
        }

        if (!found) {
          pos.first -= d;
          d = 0;
        }
      } else if (dir == eDirection::DOWN) {
        bool found = false;
        rep(i, 100) {
          auto tPos = make_pair(pos.first, pos.second - i - 1);
          if (!obs.contains(tPos)) continue;

          found = true;
          tPos.second++;
          d -= abs(tPos.second - pos.second);
          pos = tPos;
          dir = eDirection::RIGHT;
          break;
        }

        if (!found) {
          pos.second -= d;
          d = 0;
        }
      }
    }
    cout << pos.first << " " << pos.second << endl;
  }
}

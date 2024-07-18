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

bool canReachToGoal(int sPos, int gPos, vector<int> lines) {
  int current = sPos;
  rep(i, lines.size()) {
    if (current == lines[i]) {
      current++;
    } else if (current == lines[i] - 1) {
      current--;
    }
  }

  return current == gPos;
}

int main() {
  while (true) {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n == 0 && m == 0 && p == 0 && q == 0) break;

    // p--, q--;

    vector<int> lines(m);
    rep(i, m) {
      int tmp;
      cin >> tmp;
      lines[i] = tmp - 1;
    }

    if (canReachToGoal(p, q, lines)) {
      cout << "OK" << endl;
      break;
    }

    bool ok = false;

    rep(i, m + 1) {
      rep(j, n - 1) {
        auto newLineItr = lines.begin() + i;
        newLineItr = lines.insert(newLineItr, j);
        if (canReachToGoal(p, q, lines)) {
          cout << n << " " << m << endl;
          ok = true;
          break;
        }
        lines.erase(newLineItr);
      }

      if (ok) break;
    }

    if (!ok) {
      cout << "NG" << endl;
    }
  }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return 1;} return 0;}
using ll = long long;
using namespace std;

bool simulate(vector<int> x, int p, int q) {
  rep(i, x.size()) {
    if (x[i] == p) p++;
    else if (x[i] == p - 1) p--;
  }
  return p == q;
}

int main() {
  while (true) {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n + m + p + q == 0) break;

    vector<int> x(m);
    rep(i, m) cin >> x[i];

    bool ok = false;
    if (simulate(x, p, q)) {
      cout << "OK" << endl;
      ok = true;
    }
    
    if (ok) continue;

    rep(i, m + 1) {
      for (int j = 1; j < n; j++) {
        auto y = x;
        y.insert(y.begin() + i, j);
        if (simulate(y, p, q)) {
          cout << j << " " << i << endl;
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (!ok)
      cout << "NG" << endl;
  }
}
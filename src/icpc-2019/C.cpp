#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) return 0;

    ll trit = 0;
    vector<int> a(n), w(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> w[i];

    set<ll> combination;

    rep(trit, (ll)pow(3, m)) {
      ll sum = 0;

      rep(i, m) {
        ll div = pow(3, i);
        ll current = trit / div % 3;
        if (current == 1) {
          sum += w[i];
        } else if (current == 2) {
          sum -= w[i];
        }
      }

      if (sum < 0) continue;

      combination.insert(sum);
    }

    vector<set<ll>> excluded;
    bool ok = true;
    rep(i, n) {
      if (!combination.count(a[i])) {
        ok = false;

        set<ll> tmp;
        for (auto e : combination) {
          tmp.insert(abs(a[i] - e));
        }

        excluded.emplace_back(tmp);
      }
    }

    if (ok) {
      cout << 0 << endl;
      return 0;
    }

    for (auto e : excluded[0]) {
      bool found = true;
      rep2(i, 1, excluded.size()) {
        if (excluded[i].count(e)) {
          found = false;
          break;
        }
      }

      if (found) {
        cout << e << endl;
        return 0;
      }
    }

    cout << -1 << endl;
  }
}

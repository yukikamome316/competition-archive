#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll ans = 0;

    bool initialized = false;
    // ok == false -> Aがリード
    bool ok = false;
    ll aDist = 0, bDist = 0;
    rep(i, n) {
      aDist += a[i];
      bDist += b[i];
      
      if (!initialized && (aDist != bDist)) {
        initialized = true;
        ok = aDist < bDist;
      } else if (initialized) {
        if (ok && (aDist > bDist)) {
          ans++;
          ok = false;
        } else if (!ok && (aDist < bDist)) {
          ans++;
          ok = true;
        }
      }
    }

    cout << ans << endl;
  }
}

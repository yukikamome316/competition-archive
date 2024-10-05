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

    ll ans = 0;
    rep(i, n) {
      int a;
      cin >> a;
      if (ans + a > 300) continue;
      ans += a;
    }

    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1), b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 0;
  rep(i, n) {
    ll x = min(a[i], b[i]);
    ans += x;
    a[i] -= x;
    b[i] -= x;

    ll y = min(a[i + 1], b[i]);
    ans += y;
    a[i + 1] -= y;
    b[i] -= y;  
  }

  cout << ans << endl;
}

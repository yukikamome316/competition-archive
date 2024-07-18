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

    vector<int> a(n);
    rep(i, n) {
      cin >> a[i];
    }

    ll ave = accumulate(a.begin(), a.end(), 0ll) / n;
    ll ans = 0;
    rep(i, n) {
      ans += (a[i] <= ave);
    }

    cout << ans << endl;
  }
}

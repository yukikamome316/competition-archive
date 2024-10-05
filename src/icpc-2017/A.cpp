#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    
    vector<int> a(n);
    rep(i, n) {
      cin >> a[i];
    }

    int ans = 0;
    rep(i, n) {
      rep(j, n) {
        if (i == j) continue;
        int sum = a[i] + a[j];
        if (sum <= m) chmax(ans, sum);
      }
    }

    if (ans == 0) {
      cout << "NONE" << endl;
    } else {
      cout << ans << endl;
    }
  }
}

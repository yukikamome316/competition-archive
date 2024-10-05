#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  
  constexpr int e = 0;
  const int k = sqrt(n);
  vector<int> a(n, e);
  vector<ll> bucket((n + k - 1) / k, e);
  
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    
    if (com == 0) {
      // add(x, y)
      a[x] += y;
      bucket[x / k] += y;
    } else if (com == 1) {
      // getSum(x, y)

      ll ans = e;
      rep(i, bucket.size()) {
        int l = i * k, r = (i + 1) * k - 1;
        
        if (x <= l && r <= y) {
          ans += bucket[i];
        } else if (x > r || y < l) {
          continue;
        } else {
          for (int j = max(x, l); j <= min(y, r); j++) {
            ans += a[j];
          }
        }
      }

      cout << ans << endl;
    }
  }
}

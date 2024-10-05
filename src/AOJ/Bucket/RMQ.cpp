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

  constexpr int init = (1ll << 31) - 1;
  int k = round(sqrt(n));

  vector<int> a(n, init);
  vector<int> bucket((n + k - 1) / k , init);

  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;

    if (com == 0) {
      // update(x, y)
      a[x] = y;
      int j = x / k;
      int l = j * k, r = (j + 1) * k;
      int minim = init;
      for (int i = l; i < min(r, n); i++) {
        minim = min(minim, a[i]);
      }
      bucket[j] = minim;
    } else if (com == 1) {
      // find(x, y)
      y++;
      int ans = init;
      rep(j, bucket.size()) {
        int l = j * k, r = min((j + 1) * k, n);
        if (x <= l && r <= y) {
          // バケットjがクエリの区間に完全に含まれる場合
          ans = min(ans, bucket[j]);
        } else if (x >= r || y <= l) {
          // 無関係なバケットの場合
          
        } else {
          // 区間が部分的にバケットjに交わる場合
          for (int i = max(x, l); i < min(y, r); i++) {
            ans = min(ans, a[i]);
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

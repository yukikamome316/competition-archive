#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    
    int cnt = 0;
    rep(i, n) {
      // iさんは、後に出発したjさん(i < j)にゴール時点で抜かされていなければ
      // 復路トップになりえる
      bool ok = true;
      rep2(j, i + 1, n) {
        if (p[i] > p[j]) ok = false;
      }
      if (ok) cnt++;
    }
    cout << cnt << endl;
  }
}
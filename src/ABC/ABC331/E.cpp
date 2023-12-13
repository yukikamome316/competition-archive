#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<pair<int, int>> a(N), b(M);
  rep(i, N) {
    int tmp;
    cin >> tmp;
    a[i] = make_pair(tmp, i);
  }
  rep(i, M) {
    int tmp;
    cin >> tmp;
    b[i] = make_pair(tmp, i);
  }

  set<pair<int, int>> ex;
  rep(i, L) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    ex.insert(make_pair(c, d));
  }

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  int ans = 0;
  rep(i, N) {
    rep(j, M) {
      if (ex.contains({a[i].second, b[j].second})) continue;

      chmax(ans, a[i].first + b[j].first);
      break;
    }
  }

  cout << ans << endl;
}
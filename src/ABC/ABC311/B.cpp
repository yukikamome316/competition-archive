#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, D;
  cin >> N >> D;
  vector<string> data(N);
  rep(i, N) cin >> data[i];

  bool end = true;
  rep(i, N) {
    bool found = false;
    rep(j, D) {
      if (data[i][j] == 'x') found = true;
    }
    if (found) end = false;
  }

  if (end) {
    cout << D << endl;
    return 0;
  }

  int ans = 0, tmp = 0;
  rep(i, D) {
    bool ok = true;
    rep(j, N) {
      if (data[j][i] == 'x') ok = false;
    }
    if (ok) {
      tmp++;
    } else {
      chmax(ans, tmp);
      tmp = 0;
    }
  }

  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  rep(i, N) cin >> h[i];

  if (N == 1) {
    cout << h[0] << endl;
    return 0;
  }

  ll ans = 0;
  rep2(i, 1, 101) {
    rep(j, N - 1) {
      if (h[j] >= i && h[j + 1] < i) ans++;
      else if (j == N - 2 && h[j + 1] >= i) ans++;
    }
  }

  cout << ans << endl;
}

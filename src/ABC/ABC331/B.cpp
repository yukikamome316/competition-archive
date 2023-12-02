#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll N, S, M, L;
  cin >> N >> S >> M >> L;

  ll ans = 2e9;
  // 6 * x + 8 * y + 12 * z >= Nを満たすx, y, zの組み合わせに対して、
  // 6 * S + 8 * M + 12 * Lを最小化する
  rep(x, N + 1) {
    rep(y, N + 1) {
      rep(z, N + 1) {
        if (6ll * x + 8ll * y + 12ll * z >= N) {
          chmin(ans, x * S + y * M + z * L);
        }
      }
    }
  }

  cout << ans << endl;
}

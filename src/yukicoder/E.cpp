#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;
  for (int bits = 0; bits < (1 << N); bits++) {
    if (__builtin_popcount(bits) != K) continue;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      if (bits & (1 << i)) {
        sum += A[i];
      }
    }
    if (sum % 998244353 <= sum % 998) {
      ans++;
      ans %= 998;
    }
  }

  cout << ans << endl;
}
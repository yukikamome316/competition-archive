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
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  ll t = accumulate(A.begin(), A.end(), 0ll) / N;

  ll ans = 0;
  rep(i, N) {
    if (A[i] <= t) {
      ans += A[i];
    } else {
      ans += t;
    }
  }

  cout << ans << endl;
}

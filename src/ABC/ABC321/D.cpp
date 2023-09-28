#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<int> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];

  sort(B.begin(), B.end());
  
  vector<ll> s(M + 1);
  s[0] = 0;
  rep(i, M) s[i + 1] = s[i] + B[i];
  
  ll ans = 0;
  rep(i, N) {
    auto itr = lower_bound(B.begin(), B.end(), P - A[i]);
    ans += (ll)P * (B.end() - itr);
    ans += s[(ll)(itr - B.begin())];
    ans += (ll)A[i] * (itr - B.begin());
  }

  cout << ans << endl;
}
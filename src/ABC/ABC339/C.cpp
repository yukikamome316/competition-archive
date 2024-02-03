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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> s(N + 1);
  rep(i, N) s[i + 1] = s[i] + A[i];
  ll s_min = *min_element(s.begin(), s.end());
  if (s_min < 0) {
    cout << -s_min + s[N] << endl;
  } else {
    cout << s[N] << endl;
  }
}

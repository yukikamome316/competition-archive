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
  string S;
  cin >> S;

  vector<ll> sq;

  for (ll i = 0; i * i <= 9999999999999; i++) {
    sq.push_back(i * i);
  }

  vector<int> cnt(10);
  rep(i, N) cnt[S[i] - '0']++;

  int ans = 0;
  for (ll x : sq) {
    string sq_str = to_string(x);
    vector<int> x_cnt(10);
    rep(i, sq_str.size()) x_cnt[sq_str[i] - '0']++;

    if (sq_str.size() < N) x_cnt[0] += N - sq_str.size();

    if (x_cnt == cnt) ans++;
  }

  cout << ans << endl;
}
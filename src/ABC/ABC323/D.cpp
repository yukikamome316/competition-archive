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
  map<ll, ll> cnt;
  rep(i, N) {
    ll si;
    ll ci;
    cin >> si >> ci;
    cnt[si] += ci;
  }

  ll ans = 0;
  auto itr = cnt.begin();
  while (itr != cnt.end()) {
    ll s = itr->first;
    ll c = itr->second;

    if (c > 1) cnt[2 * s] += c / 2;
    if (c & 1) ans++;
    itr++;
  }

  cout << ans << endl;
}
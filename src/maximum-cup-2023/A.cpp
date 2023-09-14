#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll N;
  cin >> N;
  map<ll, ll> mp;
  rep(i, N) {
    ll x;
    cin >> x;
    mp[x]++;
  }

  ll cnt = 0;
  for (auto [key, val] : mp) {
    cnt += val * (val - 1) / 2;
  }

  cout << cnt << endl;
}
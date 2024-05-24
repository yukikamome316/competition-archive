#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<ll, ll>> primef(ll n) {
  vector<pair<ll, ll>> r;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i) continue;

    ll e = 0;
    while (n % i == 0) {
        e++;
        n /= i;
    }
    r.push_back({i, e});
  }
  if (n != 1) r.push_back({n, 1});
  return r;
}

int main() {
  while (true) {
    ll n;
    cin >> n;
    if (n == 0) break;
    
    auto result = primef(n);
    // cout << "hi" << endl;
    
    cout << endl;
  }
}

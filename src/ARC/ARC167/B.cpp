#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace atcoder;
using mint = modint998244353;

int main() {
  ll A, B;
  cin >> A >> B;
  vector<pair<ll, ll>> factorize(0);
  for (ll i = 2; i * i <= A; i++) {
    int cnt = 0;
    while (A % i == 0) {
      cnt++;
      A /= i;
    }

    if (cnt != 0) factorize.push_back({i, cnt});
  }
  if (A != 1) factorize.push_back({A, 1});

  mint ans = B;
  for (auto [p, e] : factorize) {
    mint tmp = B;
    tmp *= e;
    tmp += 1;
    ans *= tmp;
  } 
  ans /= 2;

  cout << ans.val() << endl;
}
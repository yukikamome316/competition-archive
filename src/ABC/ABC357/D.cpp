#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll n;
  cin >> n;
  string s = to_string(n);
  ll l = s.size();
  
  mint r = 10;
  r = r.pow(l);

  mint ans = r.pow(n) - 1;
  ans *= n;
  ans /= r - 1;

  cout << ans.val() << endl;
}

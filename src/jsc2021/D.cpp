#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, P;
  cin >> N >> P;
  modint1000000007 ans = (P-1);
  vector<modint1000000007> r(70,P-2);
  rep(i,69) r[i+1] = r[i] * r[i];
  N--;
  rep(i,40) if( (N & (1LL << i)) ) ans *= r[i];
  cout << ans.val() << endl;
}
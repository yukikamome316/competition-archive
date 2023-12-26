#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> data(N);
  rep(i, N) cin >> data[i];
  rep(i, N) data[i] = abs(data[i] - X);
  int ans = data[0];
  rep(i, N) ans = gcd(ans, data[i]);
  cout << ans << endl;
}

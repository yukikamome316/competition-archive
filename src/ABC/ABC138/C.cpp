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
  vector<double> v(N);
  rep(i, N) cin >> v[i];

  double ans = -2e9;
  do {
    stack<double> s;
    rep(i, N) {
      s.push(v[i]);
    }

    while (s.size() > 1) {
      double x = s.top();
      s.pop();
      double y = s.top();
      s.pop();
      s.push((x + y) / 2);
    }

    chmax(ans, s.top());

  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string N;
  cin >> N;
  if (N.size() > 10) {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  rep(i, N.size() - 1) {
    if (N[i] <= N[i + 1]) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
}
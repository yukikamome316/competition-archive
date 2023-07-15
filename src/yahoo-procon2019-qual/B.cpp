#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  vector<set<int>> G(4);
  rep(i, 3) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].insert(b);
    G[b].insert(a);
  }

  int deg_1 = 0, deg_2 = 0;
  rep(i, 4) {
    if (G[i].size() == 1) deg_1++;
    else if (G[i].size() == 2) deg_2++;
  }

  if (deg_1 == 2 && deg_2 == 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
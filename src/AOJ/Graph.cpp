#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph_list(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, k) {
      int v;
      cin >> v;
      v--;
      graph_list[u].push_back(v);
    }
  }
  rep(i, n) {
    rep(j, n) {
      bool exists = false;
      for (int e : graph_list[i]) {
        if (e == j) {
          exists = true;
          break;
        }
      }

      cout << (int)exists;
      if (j != n - 1) cout << " ";
    }
    cout << endl;
  }
}
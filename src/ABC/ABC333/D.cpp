#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void dfs(int v, int p, vector<vector<int>> &G, vector<int> &reachable) {
  reachable[v] = 1;
  for (int u : G[v]) {
    if (u == p) continue;
    dfs(u, v, G, reachable);
    reachable[v] += reachable[u];
  }
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> G(N);
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> reachable(N);
  for (int u : G[0]) {
    dfs(u, -1, G, reachable);
  }

  int min_reachable = N;
  if (G[0].size() == 1) { // 辺0が葉である場合
    min_reachable = 1;
  } else {
    for (int u : G[0]) {
      min_reachable = min(min_reachable, reachable[u] + 1);
    }
  }

  cout << min_reachable << endl;
}

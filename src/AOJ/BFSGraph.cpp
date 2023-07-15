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
  vector<vector<int>> G(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, k) {
      int v;
      cin >> v;
      v--;
      G[u].push_back(v);
    }
  }

  vector<int> dist(n, -1);
  dist[0] = 0;

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (int e : G[x]) {
      if (dist[e] != -1) continue;
      dist[e] = dist[x] + 1;
      q.push(e);
    }
  }

  rep(i, n) {
    cout << i + 1 << " " << dist[i] << endl;
  }
}

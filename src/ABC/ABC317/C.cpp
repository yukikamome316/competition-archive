#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  vector G(N, vector<pair<int, int>>());
  vector<int> w(M);
  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--, B--;
    G[A].push_back({B, i});
    G[B].push_back({A, i});
    w[i] = C;
  }

  priority_queue<int> pq;
  ll ans = 0;

  rep(i, N) {
    vector<bool> visited(N);
    ll cost = 0;
    pq.push(i);

    while (!pq.empty()) {
      int x = pq.top();
      pq.pop();
      visited[x] = true;
      for (auto [e, idx] : G[x]) {
        if (!visited[e]) {
          visited[e] = true;
          cost += w[idx];
        }
      }
    }

    chmax(ans, cost);
  }

  cout << ans << endl;
}
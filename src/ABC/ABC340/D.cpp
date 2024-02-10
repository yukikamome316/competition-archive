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
  vector<int> A(N - 1), B(N - 1), X(N - 1);
  rep(i, N - 1) cin >> A[i] >> B[i] >> X[i];
  rep(i, N - 1) X[i]--;

  vector<vector<pair<int, int>>> G(N);
  rep(i, N - 1) G[i].push_back({i + 1, A[i]});
  rep(i, N - 1) G[i].push_back({X[i], B[i]});

  vector<ll> dist(N, 1e18);
  dist[0] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [d, v] = pq.top(); pq.pop();
    if (dist[v] < d) continue;
    for (auto [to, cost] : G[v]) {
      if (dist[to] > dist[v] + cost) {
        dist[to] = dist[v] + cost;
        pq.push({dist[to], to});
      }
    }
  }
  cout << dist[N - 1] << endl;
}

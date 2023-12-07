#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<pair<int, int>> a(N), b(M);
  rep(i, N) {
    int tmp;
    cin >> tmp;
    a[i] = make_pair(tmp, i);
  }
  rep(i, M) {
    int tmp;
    cin >> tmp;
    b[i] = make_pair(tmp, i);
  }

  set<pair<int, int>> ex;
  rep(i, L) {
    int c, d;
    cin >> c >> d;
    ex.insert(make_pair(c - 1, d - 1));
  }

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
  rep(i, N) {
    rep(j, M) {
      int current_cost = a[i].first + b[j].first;
      if (pq.empty()) {
        pq.push({current_cost, i, j});
        continue;
      }

      auto [prev_cost, _, __] = pq.top();
      if (current_cost < prev_cost && pq.size() >= L + 1) break;
      else if (pq.size() >= L + 1) pq.pop();
      pq.push({current_cost, i, j});
    }
  }

  int ans = 0;
  while (!pq.empty()) {
    auto [cost, i, j] = pq.top(); pq.pop();
    if (!ex.contains({a[i].second, b[j].second})) {
      ans = cost;
    }
  }

  cout << ans << endl;
}
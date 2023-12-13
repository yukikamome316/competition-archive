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

  // sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  vector<int> cur(N);
  priority_queue<pair<int, int>> pq;
  rep(i, N) pq.push({a[i].first + b[0].first, i});

  while (!pq.empty()) {
    auto [cost, idx] = pq.top(); pq.pop();
    if (!ex.contains({idx, b[cur[idx]].second})) {
      cout << cost << endl;
      return 0;
    }

    if (cur[idx] == M - 1) continue;
    pq.push({a[idx].first + b[++cur[idx]].first, idx});
  }
}
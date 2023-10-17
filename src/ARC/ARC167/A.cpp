#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(A.begin(), A.end(), greater<ll>());

  priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;
  vector<ll> B(M);

  rep(i, M) {
    pq.push({0, {i, 0}});
  }

  int A_idx = 0;
  while (A_idx < N) {
    auto [val, meta] = pq.top();
    auto [idx, cnt] = meta;
    pq.pop();

    if (cnt < 2) {
      B[idx] += A[A_idx];
      pq.push({B[idx], {idx, cnt + 1}});
      A_idx++;
    }
  }

  ll ans = 0;
  rep(i, M) ans += B[i] * B[i];
  cout << ans << endl;
}
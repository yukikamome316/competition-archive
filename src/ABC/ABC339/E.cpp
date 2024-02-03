#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dfs(pair<int, int> now, int &N, vector<int> &A, int &D, vector<int> &depth) {
  auto [v, idx] = now;
  if (depth[idx] != -1) return depth[idx];
  
   int ans = 0;  
   rep(i, N - idx - 1) {
    if (abs(A[idx + i + 1] - v) > D) {
      continue;
    }
    chmax(ans, dfs({A[idx + i + 1], idx + i + 1}, N, A, D, depth) + 1);
  }
  depth[idx] = ans;
  return ans;
}

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<int> depth(N, -1);
  int ans = 0;
  rep(i, N) {
    chmax(ans, dfs({A[N - i - 1], N - i - 1}, N, A, D, depth));
  }
  cout << ans + 1 << endl;
}

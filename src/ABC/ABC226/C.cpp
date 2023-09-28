#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 最適な解に到達できない
int main() {
  int N;
  cin >> N;
  // (A, T, idx)
  vector<tuple<vector<int>, int, int>> data(N);
  rep(i, N) {
    int T, K;
    cin >> T >> K;
    vector<int> tmp_vec;
    rep(j, K) {
      int A;
      cin >> A;
      tmp_vec.push_back(A);
    }
    sort(tmp_vec.begin(), tmp_vec.end());

    data[i] = make_tuple(tmp_vec, T, i + 1);
  }

  sort(data.begin(), data.end(), [](const tuple<vector<int>, int, int>& a, const tuple<vector<int>, int, int> &b) {
    auto [a_A, a_T, a_idx] = a;
    auto [b_A, b_T, b_idx] = b;

    if (a_A == b_A) {
      return a_idx > b_idx;
    }

    return a_A < b_A;
  });

  ll ans = 0;
  rep(i, N) {
    auto [A, T, idx] = data[i];

    ans += T;
    if (idx == N) break;
  }

  cout << ans << endl;
}
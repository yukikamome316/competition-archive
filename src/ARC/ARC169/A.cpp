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
  vector<ll> A(N), P(N);
  rep(i, N) cin >> A[i];
  rep(i, N - 1) {
    int tmp;
    cin >> tmp;
    P[i + 1] = tmp - 1;
  }

  rep(_, 1000) {
    // A_{P_i}をA_{P_i} + A_iで置き換える
    rep2(i, 1, N) A[P[i]] += A[i];
    rep(i, N) cout << A[i] << " ";
    cout << endl;
  }
}

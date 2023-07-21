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
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  
  ll ans = 0;
  int b_idx = 0, c_idx = 0;
  rep(i, N) {
    while (B[b_idx] <= A[i] && b_idx != N) b_idx++;
    while (C[c_idx] <= B[b_idx] && c_idx != N) c_idx++;
    if( b_idx == N || c_idx == N ){
      cout << ans << endl;
      return 0;
    }
    ans++;
    // cout << i << " " << b_idx << " " << c_idx << endl;
    b_idx++;
    c_idx++;
  }

  cout << ans << endl;
}
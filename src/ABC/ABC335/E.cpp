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
  vector<vector<int>> G(N);
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  
}

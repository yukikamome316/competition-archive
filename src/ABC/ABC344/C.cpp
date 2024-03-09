#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, L, Q;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  cin >> M;
  vector<int> B(M);
  rep(i, M) cin >> B[i];
  cin >> L;
  vector<int> C(L);
  rep(i, L) cin >> C[i];
  cin >> Q;
 
  set<ll> sum;
  rep(i, N) {
    rep(j, M) {
      rep(k, L) {
        sum.insert(A[i] + B[j] + C[k]);
      }
    }
  }

  rep(_, Q) {
    int X;
    cin >> X;
    cout << (sum.contains(X) ? "Yes" : "No") << endl;
  }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector is_black(N, vector<bool>(N, false));

  rep(i, N) {
    rep(j, N) {
      char c;
      cin >> c;
      if (c == 'B') is_black[i][j] = true;
    }
  }

  rep(i, Q) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
  }
}

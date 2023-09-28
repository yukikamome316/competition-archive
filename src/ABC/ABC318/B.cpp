#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  vector covered(101, vector<bool>(101, false));

  int N;
  cin >> N;

  rep(i, N) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int j = A; j < B; j++) {
      for (int k = C; k < D; k++) {
        covered[j][k] = true;
      }
    }
  }

  int cnt = 0;
  rep(i, 101) {
    rep(j, 101) {
      if (covered[i][j]) cnt++;
    }
  }

  cout << cnt << endl;
}
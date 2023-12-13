#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> fi(1001);

  rep(i, N) {
    int A, B;
    cin >> A >> B;
    chmax(fi[A], B);
    rep(j, B - 1) {
      if (A + j + 1 > 1000) continue;
      chmax(fi[A + j + 1], B - j - 1);

      if (A - j - 1 < 1) continue;
      chmax(fi[A - j - 1], B - j - 1);
    }
  }

  rep(i, X) {
    cout << fi[i + 1] << " ";
  }
  cout << endl;
}
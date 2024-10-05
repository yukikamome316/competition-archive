#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    int maxCnt = 0;
    int cnt = 0;
    int prev1 = 0, prev2 = 0, prev3 = 0;
    rep(i, n) {
      int a;
      cin >> a;
      cnt += a;
      cnt -= prev1;

      chmax(maxCnt, cnt);
      prev1 = prev2;
      prev2 = prev3;
      prev3 = a;
    }

    cout << maxCnt << endl;
  }
}

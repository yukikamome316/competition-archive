#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, K, S;
  cin >> N >> M >> K >> S;

  if (K == S) {
    cout << "No" << endl;
    return 0;
  }

  if (M % S != 0 && N % (K - S) != 0) {
    cout << "No" << endl;
    return 0;
  }

  int loop_cnt = min(M / S, N / (K - S));
  int one_rest = M - S * loop_cnt,
    zero_rest = N - (K - S) * loop_cnt;

  if (loop_cnt == 0 || zero_rest < 0 || one_rest < 0) {
    cout << "No" << endl;
    return 0;
  }

  if (zero_rest >= one_rest) {
    if (zero_rest <= K - S) {
      cout << "Yes" << endl;

      string sub = "";
      rep(i, K - S) sub += "0";
      rep(i, S) sub += "1";
      rep(i, loop_cnt) cout << sub;
      rep(i, zero_rest) cout << "0";

      cout << endl;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    if (one_rest <= S) {
      cout << "Yes" << endl;

      string sub = "";
      rep(i, S) sub += "1";
      rep(i, K - S) sub += "0";
      rep(i, loop_cnt) cout << sub;
      rep(i, one_rest) cout << "1";

      cout << endl;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
}
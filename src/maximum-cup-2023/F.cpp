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

  ll f = min(M / S, N / (K - S));
  ll amari = 0;

  if (M - S * f < N - (K - S) * f) {
    amari = N - f * (K - S);
    if (amari < 0) {
      cout << "No" << endl;
      return 0;
    }
    if (amari <= K - S) {
      cout << "Yes" << endl;
      string s = "";
      rep(i, K - S) s += "0";
      rep(i, S) s += "1";
      string t = s;
      rep(i, f - 1) s += t;
      rep(i, amari) s += "0";
      cout << s << endl;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    amari = M - f * S;
    if (amari < 0) {
      cout << "No" << endl;
      return 0;
    }

    if (amari <= S) {
      cout << "Yes" << endl;
      string s = "";
      rep(i, S) s += "1";
      rep(i, K - S) s += "0";
      string t = s;
      rep(i, f - 1) s += t;
      rep(i, amari) s += "1";
      cout << s << endl;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
}
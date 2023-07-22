#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  string S;
  cin >> N >> S;
  bool a = false, b = false, c = false;
  rep(i, N) {
    if (S[i] == 'A') a = true;
    else if (S[i] == 'B') b = true;
    else if (S[i] == 'C') c = true;

    if (a && b && c) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
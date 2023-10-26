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

  int l = 0;
  for (int i = 1; i < N; i++) {
    int ans = 0;
    for (int k = 0; k < N - i; k++) {
      if (S[k] != S[k + i]) ans++;
      else break;
    }
    cout << ans << endl;
  }
  
}
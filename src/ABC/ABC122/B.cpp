#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string S;
  cin >> S;

  string key = "ACGT";
  int max_length = 0;
  int tmp = 0;

  rep(i, S.size()) {
    bool ok = false;
    rep(j, 4) {
      if (S[i] == key[j]) ok = true;
    }
    if (ok) {
      tmp++;
    } else {
      chmax(max_length, tmp);
      tmp = 0;
    }
  }
  
  chmax(max_length, tmp);
  cout << max_length << endl;
}
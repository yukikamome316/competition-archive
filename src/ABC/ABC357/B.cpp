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

  int lower_cnt = 0, upper_cnt = 0;

  rep(i, S.size()) {
    if (islower(S[i])) lower_cnt++;
    else upper_cnt++;
  }

  if (upper_cnt > lower_cnt) {
    rep(i, S.size()) {
      if (islower(S[i])) S[i] = toupper(S[i]);
    }
  } else {
    rep(i, S.size()) {
      if (isupper(S[i])) S[i] = tolower(S[i]);
    }
  }

  cout << S << endl;
}

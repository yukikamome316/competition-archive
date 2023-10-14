#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;

  set<int> ans;

  vector<int> T_cnt(26);
  rep(i, T.size()) T_cnt[T[i] - 'a']++;

  rep(i, N) {
    string S;
    cin >> S;
    if (abs((int)S.size() - (int)T.size()) > 1) continue;

    vector<int> S_cnt(26);
    rep(j, S.size()) S_cnt[S[i] - 'a']++;

    bool edited = false;
    rep(j, 26) {
      if (T_cnt[j] > S_cnt[j]) {
        char ch = j + 'a';
        bool found = false;
        rep(k, S.size() + 1) {
          string tmp = S;
          S.insert(S.begin() + k, ch);
          if (tmp == T) {
            ans.insert(i + 1);
            found = true;
            break;
          }

          if (found) break;
        }
      // } else (T_cnt[j] < S_cnt[j]) {

      // }
    }
  }

}
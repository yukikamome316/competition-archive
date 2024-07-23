#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  sort(s.begin(), s.end());

  int str_cnt = 0;
  int case_cnt = 0;
  do {
    rep(i, n - k + 1) {
      bool ok = true;
      rep(j, k) {
        if (s[i + j] != s[i + k - j - 1]) {
          ok = false;
        }
      }
      if (ok) {
        str_cnt++;
        break;
      }
    }

    case_cnt++;
  } while (next_permutation(s.begin(), s.end()));

  cout << case_cnt - str_cnt << endl;
}

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

    int curIdx = 0;
    string ans = "";
    rep(i, n) {
      string mode;
      char c;
      cin >> mode >> c;
      if (mode == "INSERT") {
        ans.insert(ans.begin() + curIdx, c);
        curIdx++;
      } else if (mode == "LEFT") {
        curIdx = max(curIdx - 1, 0);
      } else if (mode == "RIGHT") {
        curIdx = min(curIdx + 1, (int)ans.size());
      }
    }
    cout << ans << endl;
  }
}

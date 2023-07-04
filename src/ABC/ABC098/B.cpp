#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  rep(i, N) {
    string left = S.substr(0, i);
    string right = S.substr(i, N - i);

    set<char> cap;
    rep(j, left.size()) {
      rep(k, right.size()) {
        if (left[j] == right[k])
          cap.insert(left[j]);
      }
    }

    ans = max(ans, (int)cap.size());
  }

  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int ans = 0, b = 0;
  rep(i, S.size()) {
    if (S[i] == 'W') ans += b;
    else b++;
  }

  cout << ans << endl;
}
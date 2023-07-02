#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<char> s(N, '.');
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    if (s[x - 1] != '.' && s[x - 1] != y + '0') {
      cout << -1 << endl;
      return 0;
    }
    s[x - 1] = y + '0';
  }

  if (s[0] == '0' && N >= 2) {
    cout << -1 << endl;
    return 0;
  }

  if (s[0] == '.' && N >= 2) {
    s[0] = '1';
  }

  rep(i, N) {
    if (s[i] == '.') {
      s[i] = '0';
    }
  }

  rep(i, N) {
    cout << s[i];
  }
  cout << endl;
}
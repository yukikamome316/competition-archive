#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool ok(char a, char b) {
  int dist = abs(a - b);
  return dist == 1 || dist == 4;
}
int main() {
  char S1, S2, T1, T2;
  cin >> S1 >> S2 >> T1 >> T2;

  S1 -= 'A';
  S2 -= 'A';
  T1 -= 'A';
  T2 -= 'A';

  if (ok(S1, S2) && ok(T1, T2)) cout << "Yes" << endl;
  else if (!ok(S1, S2) && !ok(T1, T2)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

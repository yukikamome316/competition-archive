#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << endl;
    return 0;
  }

  set<int> st = {0, 1, 2};
  st.erase(x);
  st.erase(y);
  cout << *st.begin() << endl;
}

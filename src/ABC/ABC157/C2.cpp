#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  
  set<int> st;
  rep(i, 1000) {
    if (N == 1) {
      if (i <= 9) st.insert(i); 
    } else if (N == 2) {
      if (i >= 10 && i <= 99) st.insert(i);
    } else {
      if (i >= 100) st.insert(i);
    }
  }

  rep(i, M) {
    int s, c;
    cin >> s >> c;
    set<int> tmp(st.begin(), st.end());
    for (int x : tmp) {
      string x_str = to_string(x);
      if (x_str.size() < s) {
        st.erase(x);
        continue;
      }
      if (x_str[s - 1] - '0' != c) st.erase(x);
    }
  }
  
  if (st.size() == 0) cout << -1 << endl;
  else cout << *st.begin() << endl;
}

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
  vector<int> D(N);
  rep(i, N) cin >> D[i];

  ll ans = 0;
  rep(i, N) {
    string s = to_string(i + 1);
    
    for (int j = 1; j <= D[i]; j++) {
      string t = to_string(j);
      set<int> st;
      for (auto e : s) {
        st.insert(e - '0');
      }
      for (auto e : t) {
        st.insert(e - '0');
      }
      if (st.size() == 1) ans++;
    }
  }

  cout << ans << endl;
}

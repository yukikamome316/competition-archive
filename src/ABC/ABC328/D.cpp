#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string S;
  cin >> S;

  stack<char> st;
  rep(i, S.size()) {
    st.push(S[i]);
    if (st.size() >= 3) {
      char c = st.top();  st.pop();
      char b = st.top();  st.pop();
      char a = st.top();  st.pop();
      if (a == 'A' && b == 'B' && c == 'C') {
        continue;
      } else {
        st.push(a);
        st.push(b);
        st.push(c);
      }
    }
  }
  
  string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

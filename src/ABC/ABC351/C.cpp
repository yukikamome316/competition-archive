#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n;
  cin >> n;
  
  stack<int> st;
  rep(i, n) {
    int a;
    cin >> a;
    st.push(a);
    while (st.size() > 1) {
      int a1 = st.top();
      st.pop();
      int a2 = st.top();
      st.pop();

      if (a1 == a2) {
        st.push(a1 + 1);
      } else {
        st.push(a2);
        st.push(a1);
        break;
      }
    }
  }
  cout << st.size() << endl;
}

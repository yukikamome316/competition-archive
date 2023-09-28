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
  vector a(N, vector<int>());
  set<vector<int>> st;  // 種類のカウントはsetの利用を最初に考える
  rep(i, N) {
    int L;
    cin >> L;

    rep(j, L) {
      int tmp;
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }

  rep(i, N) {
    st.insert(a[i]);
  }

  cout << st.size() << endl;
}

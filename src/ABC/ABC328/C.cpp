#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  
  vector<int> st(N + 1);
  rep2(i, 1, N) st[i] = st[i - 1] + (S[i] == S[i - 1] ? 1 : 0);

  rep(_, Q) {
    int l, r;
    cin >> l >> r;
    cout << st[r - 1] - st[l - 1] << endl;
  }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N1, N2, M;
  cin >> N1 >> N2 >> M;
  vector<set<int>> G(N1 + N2 + 1);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G[a - 1].insert(b - 1);
    G[b - 1].insert(a - 1);
  }

  vector<int> dist(N1, -1);
  

}
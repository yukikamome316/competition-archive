#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<pair<int, int>> a(N), b(M);
  rep(i, N) {
    int a_tmp;
    cin >> a_tmp;
    a[i] = {a_tmp, i};
  }

  rep(i, M) {
    int b_tmp;
    cin >> b_tmp;
    b[i] = {b_tmp, i};
  }

  set<pair<int, int>> ex;
  rep(i, L) {
    int c, d;
    cin >> c >> d;
    ex.insert({c, d});
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ai = N - 1, bi = M - 1;
  int max_sum = 0;
  while (ai >= 0 && bi >= 0) {
    while (ai >= 0 && ex.contains({a[ai].second, b[bi].second})) ai--;
    if (ai < 0) break;
    chmax(max_sum, a[ai].first + b[bi].first);
    break;
  }

  ai = N - 1, bi = M - 1;
  while (ai >= 0 && bi >= 0) {
    while (bi >= 0 && ex.contains({a[ai].second, b[bi].second})) bi--;
    if (bi < 0) break;
    chmax(max_sum, a[ai].first + b[bi].first);
    break;
  }

  cout << max_sum << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> C(N);
  rep(i, N) cin >> C[i];
  map<int, dsu> mp;

  map<int, int> cnt;
  rep(i, N) cnt[C[i]]++;

  rep(i, M) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;

    if (C[v1] == C[v2]) {
      if (mp.find(C[v1]) == mp.end()) mp[C[v1]] = dsu(N);
      mp[C[v1]].merge(v1, v2);
    }
  }

  int ans = 0;
  for (auto [k, v] : mp) {
    ans += v.groups().size() - (N - cnt[k]) - 1;
  }

  cout << ans << endl;

}
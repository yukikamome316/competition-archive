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
  vector<set<int>> A(N);
  rep(i, N) {
    int C;
    cin >> C;
    rep(j, C) {
      int tmp;
      cin >> tmp;
      A[i].insert(tmp);
    }
  }

  int X;
  cin >> X;

  vector<pair<int, int>> ans;
  rep(i, N) {
    if (A[i].count(X) != 0) ans.push_back({A[i].size(), i + 1});
  }

  sort(ans.begin(), ans.end());

  int min_val = 2e9;
  map<int, int> mp;
  rep(i, ans.size()) {S
    chmin(min_val, ans[i].first);
    mp[ans[i].first]++;
  }

  cout << mp[min_val] << endl;
  rep(i, ans.size()) {
    if (ans[i].first == min_val) cout << ans[i].second << " ";
  }
  cout << endl;
}
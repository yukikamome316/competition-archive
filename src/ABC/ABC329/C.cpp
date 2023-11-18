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
  string S;
  cin >> S;

  vector<pair<char, int>> rle;
  rle.push_back({S[0], 0});
  rep(i, N) {
    if (rle.back().first == S[i]) {
      rle.back().second++;
    } else {
      rle.push_back({S[i], 1});
    }
  }

  map<char, int> mp;
  for (auto [k, v] : rle) {
    mp[k] = max(mp[k], v);
  }

  int ans = 0;
  for (auto [k, v] : mp) {
    ans += v;
  }

  cout << ans << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int n, m;
  cin >> n >> m;

  set<int> st;
  rep(i, n) {
    st.insert(i);
  }

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    if (st.contains(u)) st.erase(u);
    if (st.contains(v)) st.erase(v);
  }

  vector<int> alpha(n), beta(n);
  
  int alpha_zero_cnt = 0;
  rep(i, n) {
    cin >> alpha[i];
    if (alpha[i] == 0) {
      alpha_zero_cnt++;
    }
  }
  rep(i, n) {
    cin >> beta[i];
  }

  bool same = true;
  rep(i, n) {
    if (alpha[i] != beta[i]) {
      same = false;
    }
  }
  if (n == 2 && !same) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> diff;
  rep(i, n) {
    if (alpha[i] != beta[i]) {
      if (!st.contains(i)) {
        cout << -1 << endl;
        return 0;
      }

      diff.emplace_back(i);
    }
  }
  
  cout << diff.size() << endl;

  deque<pair<int, int>> ans;
  rep(i, diff.size()) {
    ans.push_back(make_pair(beta[diff[i]], diff[i]));
  }

  sort(ans.begin(), ans.end());

  int rem = (alpha_zero_cnt > n / 2 ? 0 : 1);
  int ans_size = ans.size();
  rep(i, ans_size) {
    if (i % 2 == rem) {
      auto [c, v] = ans.back();
      ans.pop_back();

      cout << v + 1 << " " << c << endl;

      if (c == 0) {
        alpha_zero_cnt--;
      } else {
        alpha_zero_cnt++;
      }
    } else {
      auto [c, v] = ans.front();
      ans.pop_front();

      cout << v + 1 << " " << c << endl;

      if (c == 0) {
        alpha_zero_cnt--;
      } else {
        alpha_zero_cnt++;
      }
    }
  }
}

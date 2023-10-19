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
  vector<pair<int, int>> data(N);
  rep(i, N) {
    int L, R;
    cin >> L >> R;
    data[i] = {L, R};
  }

  vector<int> s(200001);

  rep(i, N) {
    auto [l, r] = data[i];
    s[l]++;
    s[r]--;
  }

  rep(i, 200001) {
    s[i + 1] += s[i];
  }

  set<pair<int, int>> st;

  bool found = true;
  int left = 1;
  rep2(i, 1, 200001) {
    if (!found && s[i] == 0) {
      found = true;
      st.insert({left, i});
    } else if (found && s[i] != 0) {
      left = i;
      found = false;
    }
  }

  for (auto [l, r] : st) {
    cout << l << " " << r << endl;
  }
}
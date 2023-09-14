
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  string S;
  cin >> N >> M >> S;
  vector<int> C(N);
  vector<int> cnt(M);
  rep(i, N) {
    int tmp;
    cin >> tmp;
    tmp--;
    C[i] = tmp;
    cnt[tmp]++;
  }

  vector<pair<int, char>> pos(N);
  rep(i, N) {
    pos[i] = {C[i], S[i]};
  }

  stable_sort(pos.begin(), pos.end());

  int idx = 0;
  rep(i, M) {
    auto tmp = pos[idx + cnt[i] - 1];
    rep(j, cnt[i] - 1) {
      pos[idx + cnt[i] - j - 1] = pos[idx + cnt[i] - j - 2];
    }
    pos[idx] = tmp;
    idx += cnt[i];
  }

  vector<string> S_vec(M);
  rep(i, N) {
    S_vec[pos[i].first].push_back(pos[i].second);
  }

  vector<int> C_cnt(M);
  rep(i, N) {
    cout << S_vec[C[i]][C_cnt[C[i]]];
    C_cnt[C[i]]++;
  }
  cout << endl;
}
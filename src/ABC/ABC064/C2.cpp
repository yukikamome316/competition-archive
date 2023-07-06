#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  // 範囲の左側だけを持っておけば十分
  vector<int> line = {1, 400, 800, 1200, 1600, 2000, 2400, 2800, 5050};

  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  // 種類はsetで管理して、size()で取得
  set<int> color;
  int high_cnt = 0;
  rep(i, N) {
    if (a[i] >= 3200) {
      // レート3200以上はcolorに含めないで別に管理
      high_cnt++;
      continue;
    }

    rep(j, line.size() - 1) {
      if (a[i] >= line[j] && a[i] < line[j + 1])
        color.insert(j);
    }
  }

  // N == 0となることはない
  cout << max((int)color.size(), 1) << " ";
  cout << color.size() + high_cnt << endl;
}
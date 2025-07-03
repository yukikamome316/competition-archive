#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  while (true) {
    int m, n_min, n_max;
    cin >> m >> n_min >> n_max;

    if (m == 0 && n_min == 0 && n_max == 0) {
      break;
    }

    // 1-indexed score data
    vector<int> data(m + 1);
    rep(i, m) {
      cin >> data[i + 1];
    }

    sort(data.begin() + 1, data.end(), greater<int>());

    int n_max_result = -1;
    int diff_max = -1;
    for (int n = n_min; n <= n_max; n++) {
      int diff = data[n] - data[n + 1];
      if (diff >= diff_max) {
        diff_max = diff;
        n_max_result = n;
      }
    }

    cout << n_max_result << endl;
  }

  return 0;
}

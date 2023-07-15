#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> spos(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    spos[i] = {a, b};
  }
  vector<pair<int, int>> cpos(M);
  rep(i, M) {
    int c, d;
    cin >> c >> d;
    cpos[i] = {c, d};
  }

  rep(i, N) {
    vector<int> distances(M, 2e9);
    rep(j, M) {
      int x_diff = abs(cpos[j].first - spos[i].first);
      int y_diff = abs(cpos[j].second - spos[i].second);
      distances[j] = x_diff + y_diff;
    }
    int min_distance = *min_element(distances.begin(), distances.end());
    rep(j, M) {
      if (distances[j] == min_distance) {
        cout << j + 1 << endl;
        break;
      }
    }
  }
}
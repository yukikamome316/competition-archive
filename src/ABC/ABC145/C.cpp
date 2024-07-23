#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

double dist(pair<int, int> a, pair<int, int> b) {
  auto [x1, y1] = a;
  auto [x2, y2] = b;
  
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }

  sort(p.begin(), p.end());

  double ave = 0.0;
  int cnt = 0;
  do {
    rep(i, n - 1) {
      ave += dist(p[i], p[i + 1]);
    }
    cnt++;
  } while (next_permutation(p.begin(), p.end()));
  
  ave /= cnt;

  cout << fixed << setprecision(10) << ave << endl;
}

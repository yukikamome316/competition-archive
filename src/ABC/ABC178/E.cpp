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
  vector<int> z(N), w(N);
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    z[i] = x + y;
    w[i] = x - y;
  }

  // max(abs(x_i - x_j) + abs(y_i - y_j))
  // = max(max(abs((x_i + y_j) - (x_j + y_i)), abs(x_i - y_j) -(x_j - y_j)))
  // = max(max(x_i + y_i) - min(x_i + y_i), max(x_i - y_i) - min(x_i - y_i))

  sort(z.begin(), z.end());
  sort(w.begin(), w.end());
  
  int z_min = z[0];
  int z_max = z[N - 1];

  int w_min = w[0];
  int w_max = w[N - 1];

  cout << max(z_max - z_min, w_max - w_min) << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, K;
  cin >> N >> K;

  int dist_sum = 0;
  rep(i, N) {
    int x;
    cin >> x;
    dist_sum += 2 * min(abs(x), abs(x - K));
  }

  cout << dist_sum << endl;
}
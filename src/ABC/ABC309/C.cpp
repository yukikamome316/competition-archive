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
  vector<pair<int, int>> data(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    data[i] = {a, b};
  }

  sort(data.begin(), data.end());
  vector<ll> table(N + 1);
  rep(i, N) {
    table[0] += data[i].second;
  }

  if (table[0] <= K) {
    cout << 1 << endl;
    return 0;
  }
  rep(i, N) {
    table[i + 1] = table[i] - data[i].second;
  }

  rep(i, N + 1) {
    if (table[i] <= K) {
      cout << data[i - 1].first + 1 << endl;
      return 0;
    }
  }
}
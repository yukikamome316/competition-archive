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
  vector<double> v(N);
  rep(i, N) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  while (v.size() > 1) {
    v[1] = (double)(v[0] + v[1]) / 2;
    v.erase(v.begin());
  }

  cout << v[0] << endl;
}
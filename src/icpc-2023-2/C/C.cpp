#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<vector<int>> a(n, vector<int>(n)), b(0), c(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) continue;
      b.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 != 0) continue;
      b.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j % 2 == 0) continue;
        c[i].push_back(b[i][j]);
      }
      for (int j = 0; j < n; j++) {
        if (j % 2 != 0) continue;
        c[i].push_back(b[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << c[i][j] << " ";
      }
      cout << endl;
    }
  }
}

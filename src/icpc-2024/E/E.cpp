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
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    int ind1 = 0, ind2 = n - 1;
    for (int i = n - 1; i > 0; i--) {
      if (c[0] == c[i]) {
        ind1 = i;
        break;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (c[n - 1] == c[i]) {
        ind2 = i;
        break;
      }
    }
    if (ind1 > ind2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
      continue;
    }
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
      if (0 <= i and i < ind2) a[ind1][i] = c[i];
      else if (ind2 <= i and i <= ind1) a[n - 1][i] = c[i];
      else a[n - ind1 - 1][i] = c[i];
    }
    rep(i, n) {
      if (0 <= i and i < ind2) a[i][n - ind1 - 1] = c[i];
      else if (ind2 <= i and i <= ind1) a[i][0] = c[i];
      else a[i][ind2] = c[i];
    }
    reverse(begin(c), end(c));
    for (int i = 0; i < n; i++) {
      if (0 <= i and i < ind2) a[ind1][i] = c[i];
      else if (ind2 <= i and i <= ind1) a[n - 1][i] = c[i];
      else a[n - ind1 - 1][i] = c[i];
    }
    rep(i, n) {
      if (0 <= i and i < ind2) a[i][n - ind1 - 1] = c[i];
      else if (ind2 <= i and i <= ind1) a[i][0] = c[i];
      else a[i][ind2] = c[i];
    }
    rep(i, n) {
      rep(j, n) { 
        if (j == n - 1) cout << a[i][j];
        else cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
}

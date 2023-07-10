#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int min_diff = 2e9;
    int min_idx = -1;
    rep(i, n) {
      if (min_diff > abs(a[i] - 2023)) {
        min_diff = abs(a[i] - 2023);
        min_idx = i;
      }
    }

    cout << min_idx + 1<< endl;
  }
}
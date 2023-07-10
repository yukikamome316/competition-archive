#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<int> data(n);
    rep(i, n) {
      cin >> data[i];
    }

    int cnt = 0;
    rep(i, n - 2) {
      if (data[i + 1] - data[i] > 0 && data[i + 2] - data[i + 1] < 0) {
        cnt++;
      }
    }

    cout << cnt << endl;
  }
}
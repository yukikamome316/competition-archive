#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> data(8);
  rep(i, 8) cin >> data[i];

  bool ok = true;
  rep(i, 7) {
    if (!ok) break;
    if (data[i + 1] - data[i] < 0) ok = false;
    if (data[i] < 100 || data[i] > 675 || data[i + 1] < 100 || data[i + 1] > 675) ok = false;
    if (data[i] % 25 != 0 || data[i + 1] % 25 != 0) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
}
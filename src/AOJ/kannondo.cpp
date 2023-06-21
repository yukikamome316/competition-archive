#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (!n) return 0;

    ll dp[n + 1];
    dp[0] = 1;
    rep2(i, 1, n + 1) {
      if (i == 1) dp[i] = dp[i - 1];
      else if (i == 2) dp[i] = dp[i - 1] + dp[i - 2];
      else dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    ll result = (dp[n] + 9) / 10;
    cout << (result + 364) / 365 << endl;
  }
}
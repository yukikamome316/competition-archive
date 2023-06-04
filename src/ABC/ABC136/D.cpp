#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

void checker(string S, const int N) {
  vector<int> cnt(N, 1);

    vector<int> results(N, 1);
    rep(i, 10) {
      rep(j, N) {
        results[j] -= cnt[j];
        if (S[j] == 'R') {
          results[j + 1] += cnt[j];
        } else {
          results[j - 1] += cnt[j];
        }
      }
      cout << i << ": "; 
      rep(j, N)
        cout << results[j] << " ";
      cout << endl;
      cnt = results;
    }
}

int main() {
  string S;
  cin >> S;
  const int N = S.size();

  int log2_K = 10;
  for (int i = 60; i >= 0; i--) {
    if (log2_K & (1ll << i)) {
      log2_K *= i;
      break;
    }
  }

  vector dp(N, vector<int>(log2_K + 1));
  rep(i, N) {
    if (S[i] == 'R') dp[i][0] = i + 1;
    if (S[i] == 'L') dp[i][0] = i - 1;
  }

  for (int i = 0; i < log2_K; i++) {
    for (int j = 0; j < N; j++) {
      dp[j][i + 1] = dp[dp[j][i]][i];
    }
  }

  // checker(S, N);

  vector<int> ans(N);
  rep(i, N)
    ans[dp[i][log2_K - 1]]++;

  rep(i, N - 1)
    cout << ans[i] << " ";
  cout << ans[N - 1] << endl;
}

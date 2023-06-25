#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  rep(i, N) {
    rep(j, N) {
      if (i == j) continue;

      string word = S[i] + S[j];
      bool ok = true;
      rep(k, word.size()) {
        if (word[k] != word[word.size() - k - 1])
          ok = false;
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
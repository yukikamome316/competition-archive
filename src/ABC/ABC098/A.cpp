#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<int> left(N + 1), right(N + 1);
  rep(i, N)
    left[i + 1] = left[i] + (int)(S[i] == 'W');
  rep(i, N)
    right[i + 1] = right[i] + (int)(S[N - i - 1] == 'E');

  int cnt = INT_MAX;
  rep(i, N) {
    cnt = min(cnt, right[i] + left[N - i - 1]);
  }

  cout << cnt << endl;
}
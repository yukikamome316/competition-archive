#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  // C = N - A * B > 0
  // A = iとすると
  // C > 0を満たすには
  // B = floor((N - 1) / i)C = N - A * B > 0

  ll cnt = 0;
  for (int i = 1; i < N; i++) {
    cnt += (N - 1) / i;
  }

  cout << cnt << endl;
}
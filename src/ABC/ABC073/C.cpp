#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
    cin >> A[i];

  map<int, int> mp;
  rep(i, N)
    mp[A[i]]++;

  int cnt = 0;
  // ループ回数を間違えていた
  rep(i, (1ll << 25) + 1) {
    if (mp.count(i) == 0) continue;
    if (mp[i] >= 2) 
      cnt += mp[i] - 1;
  }

  cout << cnt << endl;
} 

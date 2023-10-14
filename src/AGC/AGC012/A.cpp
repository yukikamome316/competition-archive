#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  rep(i, 3 * N) cin >> a[i];

  sort(a.begin(), a.end());

  int left = 0, right = 3 * N - 1, mid = right - 1;
  
  ll ans = 0;
  while (left < mid) {
    ans += a[mid];
    right -= 2;
    mid = right - 1;
    left++;
  }

  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> s(N);
  rep(i, N) cin >> s[i];

  rep(i, N) {
    if (s[i] == 0) {
      cout << N << endl;
      return 0;
    }    
  }

  int right = 0;
  int ans = 0;
  ll prod = 1;

  rep(left, N) {
    while (right < N && prod * s[right] <= K) {
      prod *= s[right];
      right++;
    }
    
    chmax(ans, right - left);
    if (left == right) right++;
    else prod /= s[left];
  }

  cout << ans << endl;
}
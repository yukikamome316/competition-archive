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
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  vector<int> A_sorted = A;
  sort(A_sorted.begin(), A_sorted.end());
  vector<ll> s(N + 1);
  s[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    s[i] = s[i + 1] + A_sorted[i];
  }
  
  rep(i, N) {
    int idx = upper_bound(A_sorted.begin(), A_sorted.end(), A[i]) - A_sorted.begin();
    cout << s[idx] << endl;
  }
}

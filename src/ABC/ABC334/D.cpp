#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> R(N);
  rep(i, N) cin >> R[i];
  
  sort(R.begin(), R.end());
  vector<ll> s(N + 1);
  rep(i, N) s[i + 1] = s[i] + R[i];

  rep(_, Q) {
    ll X;
    cin >> X;
    auto itr = lower_bound(s.begin(), s.end(), X);
    cout << (*itr == X ? itr - s.begin() : itr - s.begin() - 1) << endl;
  }
}

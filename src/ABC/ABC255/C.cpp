#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll X, A, D, N;
  cin >> X >> A >> D >> N;
  if (D == 0) {
    cout << abs(X - A) << endl;
    return 0;
  }

  ll lower_idx = max(0ll, (X + D - A) / D);
  ll upper_idx = max(0ll, (ll)ceil((double)(X + D - A) / D));

  ll lower_val = A + D * (lower_idx - 1);
  ll upper_val = A + D * (upper_idx - 1);
  if (lower_val > upper_val) swap(lower_val, upper_val);

  ll max_val = A + D * (N - 1);
  ll min_val = A;
  if (max_val < min_val) swap(max_val, min_val);
  if (lower_val > max_val) cout << X - max_val << endl;
  else if (upper_val < min_val) cout << min_val - X << endl;
  else if (abs(X - lower_val) < abs(X - upper_val)) cout << abs(X - lower_val) << endl;
  else cout << abs(X - upper_val) << endl;
}
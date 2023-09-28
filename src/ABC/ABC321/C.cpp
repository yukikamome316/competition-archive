#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool isLikeNum(ll x) {
  string N = to_string(x);
  if (N.size() > 10) {
    return false;
  }

  bool ok = true;
  rep(i, N.size() - 1) {
    if (N[i] <= N[i + 1]) ok = false;
  }

  return ok;
}

int main() {
  int K;
  cin >> K;

  string nums = "1234567890";

  vector<ll> arr;
  for (ll bit = 1; bit < (1ll << 10); bit++) {
    string tmp = "";
    rep(i, 10) {
      if (bit & (1ll << i)) {
        tmp +=  nums[i];
      }
    }
    arr.push_back(stoll(tmp));
  }

  sort(arr.begin(), arr.end());
  cout << arr[K - 1] << endl;
}
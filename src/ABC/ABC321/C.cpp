#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int K;
  cin >> K;

  vector<ll> nums;

  rep2(bits, 1, 1ll << 10) {
    ll num = 0;
    for (int i = 9; i >= 0; i--) {
      if (bits & (1ll << i)) {
        num *= 10;
        num += i;
      }
    }

    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());
  cout << nums[K] << endl;
}
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
  
  // 同じ数を偶数回xorしても0になるので排除する
  map<int, int> cnt;
  for (auto e : A) cnt[e] ^= 1;

  int max_val = -1, x = 0;
  for (auto [k, v] : cnt) {
    // 同じ個数の山が奇数回であるのものだけxorの値に影響する
    if (v) {
      // xorに影響するものの中での個数の最大値を求めたい
      chmax(max_val, k);
      x ^= k;
    }
  }

  // xorが非ゼロなら条件なしのNimと同じ
  if (x) cout << -1 << endl;
  // xorが0のときは、kの値を変化させて何とか非ゼロにしたい
  // 同じ数の山同士を分類して、それらが全部偶数個のときはどうやっても無理
  else if (max_val == -1) cout << 0 << endl;
  // 奇数個のグループがあるときは、k=M-1とすると最大のA_iが0になって非ゼロにできる
  else cout << max_val - 1 << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N)
    cin >> A[i];

  vector<int> B(2 * N);
  rep(i, 2 * N)
    B[i] = A[i % N];

  int max_a = *max_element(A.begin(), A.end());
  fenwick_tree<ll> fw_a(max_a + 1), fw_b(max_a + 1);
  ll inv_a = 0, inv_b = 0;
  rep(i, N) {
    // 重複がある場合、「自分より前にある同じ要素」をカウントしないようにした
    inv_a += i - fw_a.sum(0, A[i] + 1);
    fw_a.add(A[i], 1);
  }

  rep(i, 2 * N) {
    inv_b += i - fw_b.sum(0, B[i] + 1);
    fw_b.add(B[i], 1);
  }

  inv_b -= inv_a * 2;

  modint1000000007 base = inv_a * K;
  modint1000000007 sub = K - 1;
  sub *= K;
  sub *= inv_b;
  sub /= 2;

  modint1000000007 ans = base + sub;
  cout << ans.val() << endl;
}
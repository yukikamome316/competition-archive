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

  // vector<int> B(2 * N);
  // rep(i, 2 * N)
  //   B[i] = A[i % N];

  int max_a = *max_element(A.begin(), A.end());
  fenwick_tree<ll> fw(max_a + 1);
  ll inv = 0;
  rep(i, N) {
    inv += i - fw.sum(0, A[i]);
    fw.add(A[i], 1);
  }

  cout << inv << endl;

}
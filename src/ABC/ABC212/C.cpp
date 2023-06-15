#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int diff = INT_MAX;
  rep(i, N) {
    int tmp = abs(*lower_bound(B.begin(), B.end(), A[i]) - A[i]);
    diff = min(diff, tmp);
  }

  rep(i, M) {
    int tmp = abs(*lower_bound(A.begin(), A.end(), B[i]) - B[i]);
    diff = min(diff, tmp);
  }

  cout << diff << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector A(N, vector<int>(M));

  rep(i, N) {
    cin >> C[i];
    rep(j, M) {
      cin >> A[i][j];
    }    
  }
  
  int min_cost = INT_MAX;
  for (int bits = 1; bits < (1 << N); bits++) {
    vector<int> sum(M);
    int cost = 0;
    for (int i = 0; i < N; i++) {
      if (bits & (1 << i)) {
        for (int j = 0; j < M; j++) {
          sum[j] += A[i][j];
        }
        cost += C[i];
      }
    }
    bool ok = true;
    rep(i, M) {
      if (sum[i] < X) ok = false;
    }
    if (ok) {
      min_cost = min(min_cost, cost);
    }
  }

  cout << (min_cost != INT_MAX ? min_cost : -1) << endl;
}
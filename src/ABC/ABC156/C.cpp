#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, N) cin >> X[i];

  int mean = accumulate(X.begin(), X.end(), 0) / N;
  int stamina_sum_left = 0, stamina_sum_right = 0;
  rep(i, N) {
    int diff_left = X[i] - mean;
    int diff_right = X[i] - (mean + 1);
    stamina_sum_left += diff_left*diff_left;
    stamina_sum_right += diff_right*diff_right;
  }

  cout << min(stamina_sum_left, stamina_sum_right) << endl;
}
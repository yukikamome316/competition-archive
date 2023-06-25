#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int sum = 0;
    rep(j, 7) {
      int tmp;
      cin >> tmp;
      sum += tmp;
    }
    cout << sum << " ";
  }
  cout << endl;

}
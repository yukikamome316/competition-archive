#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int a_sum = 0, b_sum = 0;
  rep(i, 9) {
    int a;
    cin >> a;
    a_sum += a;
  }
  rep(i, 8) {
    int b;
    cin >> b;
    b_sum += b;
  }
  cout << a_sum - b_sum + 1 << endl;
}

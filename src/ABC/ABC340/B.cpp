#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int Q;
  cin >> Q;
  vector<int> vec;
  rep(_, Q) {
    int x, y;
    cin >> x >> y;
    if (x == 1) {
      vec.push_back(y);
    } else if (x == 2) {
      cout << *(vec.rbegin() + (y - 1)) << endl;
    }
  }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    int M;
    cin >> M;
    vector<int> d(9);
    rep(i, 9) cin >> d[i];

    vector<int> arr;
    rep(i, 9) {
      rep(j, d[i]) {
        arr.push_back(i + 1);
      }
    }
    do {
      int num = 0;
      rep(i, arr.size()) {
        num *= 10;
        num += arr[i];
      }
      if (num % M == 0) {
        cout << num << endl;
        break;
      }
    } while (next_permutation(arr.begin(), arr.end()));
  }
}
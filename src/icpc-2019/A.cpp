#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    vector<int> sum(n);
    rep(i, m) {
      rep(j, n) {
        int p;
        cin >> p;
        sum[j] += p;
      }
    }

    cout << *max_element(sum.begin(), sum.end()) << endl;
  }
}

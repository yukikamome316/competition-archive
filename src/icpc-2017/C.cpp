#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    vector recipe(n, vector<bool>(m));
    rep(i, n) {
      rep(j, m) {
        int b;
        cin >> b;
        recipe[i] = static_cast<bool>(b);
      }
    }
    
    vector dp(n, vector<bool>(m));
    
  }
}

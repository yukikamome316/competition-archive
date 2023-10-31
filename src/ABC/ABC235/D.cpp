#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int getDigit(ll num) {
  int ret = 0;
  while (num != 0) {
    num /= 10;
    ret++;
  }
  return ret;
}


int main() {
  int a, N;
  cin >> a >> N;

  int N_len = getDigit(N);
  
  set<ll> seen;
  queue<pair<ll, int>> que;
  que.push({1, 0});

  while (!que.empty()) {
    auto [x, cnt] = que.front();
    que.pop();

    if (seen.count(x)) continue;
    seen.insert(x);

    if (x == N) {
      cout << cnt << endl;
      return 0;
    }

    int x_len = getDigit(x);
    if (x_len > N_len) continue;

    if (x >= 10 && x % 10 != 0) {
      string x_str = to_string(x);
      
      x_str.insert(x_str.begin(), x_str[x_len - 1]);
      x_str.erase(x_str.begin() + x_len);
      que.push({stoll(x_str), cnt + 1});
    }
    
    que.push({x * a, cnt + 1});
  }

  cout << -1 << endl;
}

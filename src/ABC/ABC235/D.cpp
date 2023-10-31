#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int a, N;

int getDigit(ll num) {
  int ret = 0;
  while (num != 0) {
    num /= 10;
    ret++;
  }
  return ret;
}

int dfs(ll x, int N_len, int cnt, bool swapped, set<ll> &seen) {
  if (x == N) return cnt;
  
  if (seen.count(x)) {
    cout << x << " duplication halt." << endl;
    return -1;
  }

  seen.insert(x);
  
  int x_len = getDigit(x);
  if (x_len > N_len) {
    cout << x << " halt." << endl;
    return -1;
  }

  int ret = -1;
  if (!swapped && x >= 10 && x % 10 != 0) {
    string x_str = to_string(x);
    x_str.insert(x_str.begin(), x_str[x_len - 1]);
    x_str.erase(x_str.begin() + x_len);
    
    ll x_swapped = stoll(x_str);
    cout << x << "->" << x_swapped << " (insert)" << endl;
    ret = dfs(x_swapped, N_len, cnt + 1, true, seen);
  }

  if (ret != -1) return ret;

  cout << x << "->" << x * a << endl;
  return dfs(x * a, N_len, cnt + 1, false, seen);
}

int main() {
  cin >> a >> N;
  int N_len = getDigit(N);

  set<ll> seen;
  cout << dfs(1, N_len, 0, false, seen) << endl;
}
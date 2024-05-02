#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string M_str = "2321357857448432";
  string prev_M = "";
  ll cnt = 0;
  bool flag = false;
  set<ll> prev;
  while (M_str != "153") {
    ll new_M = 0;
    rep(i, M_str.size()) {
      int digit = M_str[i] - '0';
      new_M += digit * digit * digit;
    }
    M_str = to_string(new_M);
    cout << M_str << endl;
    if (prev.contains(new_M)) {
      flag = true;
      break;
    }
    cnt++;
    prev.insert(new_M);
  }

  cout << (flag ? -1 : cnt) << endl;
}

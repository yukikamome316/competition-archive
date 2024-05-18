#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> sum(N + 1);
  sum[0] = 0;
  rep(i, N) {
    sum[i + 1] = sum[i] + (S[i] - '0')*(S[i] - '0')*(S[i] - '0');
  }
  
  rep(_, Q) {
    int l, r;
    cin >> l >> r;
    int next_M = sum[r] - sum[l - 1];
    if (r - l + 1 == 3) {
      string M_str = S.substr(l - 1, r - l + 1);
      if (M_str == "153") {
        cout << 153 << endl;
        continue;
      }
    }
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
      if (prev.contains(new_M)) {
        flag = true;
        break;
      }
      cnt++;
      prev.insert(new_M);
    }

    cout << (flag ? -1 : cnt) << endl;
  }
}

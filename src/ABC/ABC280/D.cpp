#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<int, int>> primef(int n) {
  vector<pair<int, int>> r;
  for (int i = 2; i * i <= n; i++) {
    if (n % i) continue;

    int e = 0;
    while (n % i == 0) {
        e++;
        n /= i;
    }
    r.push_back({i, e});
  }
  if (n != 1) r.push_back({n, 1});
  return r;
}

int main() {
  ll K;
  cin >> K;
  auto kp = primef(K);
  
  if (kp.size() == 1) {
    cout << K << endl;
    return 0;
  }
  
  map<int, int> cnt;
  rep2(i, 2, 1000000) {
    auto ip = primef(i);
    for (auto p : ip) cnt[p.first] += p.second;

    bool ok = true;
    for (auto p : kp) {
      if (!cnt.contains(p.first) || cnt[p.first] < p.second) ok = false;
    }
    
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
}

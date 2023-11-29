#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll N, K;
  cin >> N >> K;

  set<ll> seen;
  queue<ll> que;
  que.push(K);

  ll ans = 0;
  while (!que.empty()) {
    ll x = que.front();
    que.pop();

    if (seen.contains(x)) continue;
    seen.insert(x);

    que.push(x * 10);

    if (x < 1 || x > N) continue;
    ll rev_val = 0;
    while (x > 0) {
      rev_val = rev_val * 10 + x % 10;
      x /= 10;
    }

    if (rev_val < K) break;
    que.push(rev_val);

    ans++;
  }

  cout << ans << endl;
}

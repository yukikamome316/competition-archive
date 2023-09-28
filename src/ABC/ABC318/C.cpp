#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, D, P;
  cin >> N >> D >> P;
  // vector<int> F(N);
  // rep(i, N) cin >> F[i];

  priority_queue<int> pq;
  rep(i, N) {
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }

  ll ans = 0;

  while (!pq.empty()) {
    ll sum = 0;

    int cnt = 0;
    while (cnt < D && !pq.empty()) {
      int x = pq.top();
      pq.pop();
      sum += x;
      cnt++;
    }

    if (sum < P) ans += sum;
    else ans += P;
  }

  cout << ans << endl;
}
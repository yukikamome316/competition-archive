#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> pos(N);
  multiset<ll> px, py;
  rep(i, N) {
    ll x, y;
    cin >> x >> y;
    pos[i] = {x, y};
    if (i == 0) continue;
    px.insert(x);
    py.insert(y);
  }

  priority_queue<ll> pq;
  rep(i, N - 1) {
    auto [nx, ny] = pos[i];
    auto [nnx, nny] = pos[i+1];

    ll candi = max(abs(nx - *px.begin()), abs(nx - *px.rbegin()));
    candi = max(abs(ny - *py.begin()), max(abs(ny - *py.rbegin()), candi));
    pq.push(candi);

    px.erase(px.find(nnx));
    py.erase(py.find(nny));
  }
  pq.pop();
  cout << pq.top() << endl;

}
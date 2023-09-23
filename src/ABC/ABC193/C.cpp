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

  set<ll> st;
  
  for (ll i = 2; i * i <= N; i++) {
    ll x = i * i;
    while (x <= N) {
      st.insert(x);
      x *= i;
    }
  }
  
  cout << N - st.size() << endl;
}
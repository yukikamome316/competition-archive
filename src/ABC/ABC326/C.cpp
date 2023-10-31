#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  map<int, int> mp;
  set<int> st;

  rep(i, N) {
    int A;
    cin >> A;
    mp[A]++;
    st.insert(A);
  }

  vector<int> vec(st.begin(), st.end());
  vector<ll> s(N + 1);

  auto itr = mp.begin();
  rep(i, N) {
    s[i + 1] = s[i] + itr->second;
    itr++;
  }

  ll ans = 0;
  int current = 1;
  for (auto [a, cnt] : mp) {
    int val = a + M;
    auto itr = lower_bound(vec.begin(), vec.end(), val);
    if (itr != vec.begin()) {
      itr--;
      chmax(ans, s[itr - vec.begin() + 1] - s[current - 1]);
    } else {
      chmax(ans, s[current]);
    }
    
    current++;
  }
  
  cout << ans << endl;
  
}
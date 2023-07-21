#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  vector<ll> candy(3);
  rep(i,3) cin >> candy[i];
  for(int i=0;i<(1ll<<3);i++) {
    ll c1 = 0, c2 = 0;
    rep(j,3){
      if( (i & (1ll << j)) ) c1 += candy[j];
      else c2 += candy[j];
    }
    if( c1 == c2 ){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string S;
  cin >> S;
  vector<int> cnt(30);
  rep(i, S.size()) {
    cnt.at(S.at(i) - 'a')++;
  }

  cout << (char)((char)(max_element(cnt.begin(), cnt.end()) - cnt.begin()) + 'a') << endl;
}

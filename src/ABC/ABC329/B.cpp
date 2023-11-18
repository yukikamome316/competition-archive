#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  set<int> A;
  rep(i, N) {
    int tmp;
    cin >> tmp;
    A.insert(tmp);
  }
  A.erase(max_element(A.begin(), A.end()));
  cout << *max_element(A.begin(), A.end()) << endl;
}

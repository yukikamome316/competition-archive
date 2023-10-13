#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  vector<int> data(5);
  rep(i, 5) cin >> data[i];

  set<int> st;

  sort(data.begin(), data.end());
  do {
    st.insert(accumulate(data.begin(), data.begin() + 3, 0));
  } while (next_permutation(data.begin(), data.end()));

  vector<int> ans(st.begin(), st.end());

  cout << *(ans.rbegin() + 2) << endl;
}
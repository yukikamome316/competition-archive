#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i, M) cin >> A[i];

  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> que(compare);
  unordered_map<int, int> counter;
  for (int j = 0; j < M; j++) {
    counter[A[j]]++;
    que.push({counter[A[j]], A[j]});
    
    cout << que.top().second << endl;
  }
}

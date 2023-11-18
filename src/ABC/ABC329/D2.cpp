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
  vector<int> A(M);
  rep(i, M) cin >> A[i];

  priority_queue<pair<int, int>> pq;
  unordered_map<int, int> cnt;
  for (int i = 0; i < M; i++) {
    cnt[A[i]]++;
    pq.push({cnt[A[i]], -A[i]});
    
    cout << -pq.top().second << endl;
  }
}

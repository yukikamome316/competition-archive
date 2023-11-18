#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  
  vector<map<int, int>> boxes(N);
  rep(i, N) {
    map<int, int> mp;
    int C;
    cin >> C;
    mp[C]++;
    boxes[i] = mp;
  }

  rep(_, Q) {
    int src, dest;
    cin >> src >> dest;
    src--, dest--;
    
    map<int, int> null_map;
    if (boxes[src].size() <= boxes[dest].size()) {
      for (auto [k, v] : boxes[src]) {
        boxes[dest][k] += v;
      }
    } else {
      for (auto [k, v] : boxes[dest]) {
        boxes[src][k] += v;
      }
      swap(boxes[src], boxes[dest]);
    }
    
    boxes[src] = null_map;
    
    cout << boxes[dest].size() << endl;
  }
}

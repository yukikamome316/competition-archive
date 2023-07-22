#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dfs(int v, vector<bool>& visited, vector<int>& G) {
  visited[v] = true;
  int next_v = G[v];
  int ret = -1;
  if (visited[next_v]) {
    return next_v;
  }
  int tmp = dfs(next_v, visited, G);
  if (tmp != -1) ret = tmp;
  return tmp;
}

int main() {
  int N;
  cin >> N;
  vector<int> G(N);
  rep(i, N) {
    int A;
    cin >> A;
    A--;
    G[i] = A;
  }

  vector<bool> visited(N, false);
  int ret = -1;
  rep(i, N) {
    ret = dfs(i, visited, G);
    if (ret != -1) break;
  }

  vector<int> ans;
  int tmp = ret;
  do {
    tmp = G[tmp];
    ans.push_back(tmp + 1);
  } while (tmp != ret);

  cout << ans.size() << endl;
  for (int e : ans) {
    cout << e << " ";
  }
  cout << endl;

}
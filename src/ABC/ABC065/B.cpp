#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) 
    cin >> a[i], a[i]--;

  vector<vector<bool>> list(N, vector<bool>(N, false));
  rep(i, N) 
    list[i][a[i]] = true;
  
  vector<int> seen(N, -1);
  queue<int> q;
  q.push(1);
  seen[1] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    rep(i, N) {
      if (list[i][current]) {
        if (seen[i] != -1) continue; 
        q.push(i);
        seen[i] = seen[current] + 1;
      }
    }

    if (current == 0) break;
  }

  cout << seen[0] << endl;
  
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  while (true) {
    int m, n, p;
    cin >> m >> n >> p;
    if (m + n + p == 0) break;

    vector<set<int>> data(m);
    bool found = false;
    rep(i, n) {
      int a, b;
      cin >> a >> b;
      
      if (a == p || b == p) {
        found = true;
      }
      if (!found) continue;

      data[a - 1].insert(b - 1);
      data[b - 1].insert(a - 1);
    }

    queue<int> q;
    q.push(p - 1);

    vector<bool> visited(m, false);

    int cnt = 0;

    while (!q.empty()) {
      int x = q.front();
      q.pop();

      visited[x] = true;
      cnt++;

      for (int e : data[x]) {
        if (!visited[e]) {
          q.push(e);
        }
      }
    }

    cout << cnt << endl; 
  }
}
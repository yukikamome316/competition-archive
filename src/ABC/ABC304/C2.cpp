#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int INF = INT_MAX;

double distance(pair<int, int> a, pair<int, int> b) {
  double distance = sqrt(
    (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)
  );
  return distance;
}

int main() {
  int N, D;
  cin >> N >> D;
  vector<pair<int, int>> pos(N);
  rep(i, N) {
    int X, Y;
    cin >> X >> Y;
    pos[i] = {X, Y};
  }

  vector<bool> results(N, false);
  results[0] = true;

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (!results[x]) continue;

    vector<double> distances(N, INF);
    rep(i, N) {
      if (i == x) continue;
      distances[i] = distance(pos[i], pos[x]);
    }

    rep(i, N) {
      if (distances[i] <= D && !results[i]) {
        q.push(i);
        results[i] = true;
      }
    }
  }

  rep(i, N)
    cout << (results[i] ? "Yes" : "No") << endl;
}
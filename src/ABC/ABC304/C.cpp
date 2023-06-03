#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

bool hasDangerdistance(pair<int, int> a, pair<int, int> b, int d) {
  double distance = sqrt(
    (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)
  );
  return distance <= d;
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

    dsu ds(N);

    int id = 0;
    bool changed = false;
    while (true) {
      if (ds.same(0, id)) {
        rep(i, N) {
          if (i == id) continue;
          if (!ds.same(id, i) && hasDangerdistance(pos[id], pos[i], D)) {
            ds.merge(0, i);
            changed = true;
          }
        }
      }
      
      if (id == N - 1 && !changed) break;
      else if (id == N - 1 && changed) changed = false; 
      id = (id + 1) % N;
    }
    

    rep(i, N) {
      cout << (ds.same(0, i) ? "Yes" : "No") << endl;
    }
}
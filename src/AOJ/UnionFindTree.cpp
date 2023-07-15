#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind {
  vector<int> par, rank, siz;

  UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1) { }

  int root(int x) {
    if (par[x]==-1) return x;
    else return par[x] = root(par[x]);
  }

  bool same(int x, int y) {
    return root(x)==root(y);
  }

  bool merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx==ry) return false;
  
    if (rank[rx]<rank[ry]) swap(rx, ry); 
    par[ry] = rx;
    if (rank[rx]==rank[ry]) rank[rx]++; 
    siz[rx] += siz[ry];
    return true;
  }

  int size(int x) {
    return siz[root(x)];
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  struct UnionFind ds(n);
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      ds.merge(x, y);
    } else if (com == 1) {
      cout << (int)ds.same(x, y) << endl;
    }
  }
}

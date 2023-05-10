#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    dsu ds(N);
    rep(i, Q) {
        int query; cin >> query;
        int u, v; cin >> u >> v;
        if (query == 0) {    
            ds.merge(u, v);
        } else {
            cout << (ds.same(u, v) ? 1 : 0) << endl;
        }
    }
}
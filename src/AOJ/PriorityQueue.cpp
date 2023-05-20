#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;

    vector<priority_queue<int>> pq(n);
    while (q--) {
        int mode, t; cin >> mode >> t;
        if (mode == 0) {
            int x; cin >> x;
            pq[t].push(x);
        } else if (mode == 1) {
            if (pq[t].size() != 0)
                cout << pq[t].top() << endl;
        } else if (mode == 2) {
            if (pq[t].size() != 0)
                pq[t].pop();
        }
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

class Segtree {
private:
    int size;
    int log2;
    int n;
    vector<ll> data;

    void update(int i) {
        data[i] = data[2 * i] + data[2 * i + 1];
    }

public:
    Segtree(int n) {
        this->n = n;
        log2 = 0;
        while ((1LL << log2) < n) log2++;
        size = 1 << log2;
        data = vector<ll>(2 * size, 0);
    }

    void add(int i, int x) {
        i += size;
        data[i] += x;
        while (i > 1) {
            i /= 2;
            update(i);
        }
    }

    ll sum(int l, int r) {
        l += size, r += size;
        int sml = 0, smr = 0;
        while (l < r) {
            if (l & 1) sml += data[l++];
            if (r & 1) smr += data[--r];
            l /= 2, r /= 2;
        }
        return sml + smr;
    }
};

int main() {
    int n, q; cin >> n >> q;
    Segtree tree(n);
    rep(i, n) tree.add(i, 0);

    rep(i, q) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) {
            // add
            tree.add(x - 1, y);
        } else if (com == 1) {
            // getSum
            cout << tree.sum(x - 1, y) << endl;
        }
    }
    
}
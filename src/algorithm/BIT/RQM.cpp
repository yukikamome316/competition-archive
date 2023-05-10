#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

class BIT {
public:
    BIT(int _n) {
        n = _n;
        data.resize(n);
    }

    /**
     * @brief 
     * 
     * @param i 0-indexed
     * @param x value
     */
    void add(int i, int x) {
        i++;
        while (i <= n) {
            data[i - 1] += x;
            i += (i & -i);
        }
    }
    
    /**
     * @brief 
     * 
     * @param l 0-indexed
     * @param r 1-indexed
     * @return int 
     */
    int sum(int l, int r) {
        return _sum(r) - _sum(l);
    }

private:
    int n;
    vector<ll> data;

    int _sum(int i) {
        ll s = 0;
        while (i > 0) {
            s += data[i - 1];
            i -= (i & -i);
        }
        return s;
    }
};

// Range Minimum Query (RMQ): https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
int main() {
    int n, q; cin >> n >> q;
    BIT bit(n);

    rep(_, q) {
        int com; cin >> com;
        int x, y; cin >> x >> y;
        if (com == 0) {
            bit.add(x - 1, y);
        } else if (com == 1) {
            cout << bit.sum(x - 1, y) << endl;
        }
    }
}

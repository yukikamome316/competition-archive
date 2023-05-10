#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

class XorBIT {
public:
    XorBIT(int _n) {
        n = _n;
        data.resize(n);
    }

    void calcXor(int i, int x) {
        i++;
        while (i <= n) {
            data[i - 1] ^= x;
            i += i & -i;
        }
    }

    int calcXorForAll(int l, int r) {
        return _calcXorForAll(r) ^ _calcXorForAll(l);
    }


private:
    int n;
    vector<int> data;

    int _calcXorForAll(int i) {
        int s = 0;
        while (i > 0) {
            s ^= data[i - 1];
            i -= i & -i;
        } 
        return s;
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    XorBIT bit(N);

    rep(i, N) {
        int x; cin >> x;
        bit.calcXor(i, x);
    }

    rep(i, Q) {
        int com; cin >> com;
        int x, y; cin >> x >> y;
        if (com == 1) {
            bit.calcXor(x - 1, y);
        } else if (com == 2) {
            cout << bit.calcXorForAll(x - 1, y) << endl;
        }
    }
}
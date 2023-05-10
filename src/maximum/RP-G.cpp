#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

class RollingHash {
public:
    using ull = unsigned long long;

    static const ull Mod = (1LL << 61) - 1;

    RollingHash(const string &s, ull _base = 0) {
        if (_base == 0) {
            random_device rnd;
            mt19937 mt(rnd());
            uniform_int_distribution<ull> rand(128, INT_MAX);
            _base = rand(mt);
        }

        base = _base;
        powr.assign(1, 1);
        int n = s.size();
        hash.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = mulMod(hash[i], base) + s[i];
            hash[i + 1] = getMod(hash[i + 1]);
        }

    }

    ull get(int l, int r) {
        ull res = hash[r] - mulMod(hash[l], getPow(r - l));
        return getMod(res + Positivizer);
    }

    ull getBase() {
        return base;
    }

    ull getPow(int n) {
        while (powr.size() <= n) {
            powr.push_back(mulMod(powr.back(), base));
        }
        return powr[n];
    }

    ull mulMod(ull x, ull y) {
        __int128_t t = (__int128_t)x * y;
        t = (t >> 61) + (t & Mod);
        if (t >= Mod) t -= Mod;
        return (ull)t;
    }

private:
    static const ull Positivizer = 7 * Mod;
    ull base;
    vector<ull> hash;
    vector<ull> powr;

    ull getMod(ull val) {
        val = (val & Mod) + (val >> 61);
        if (val >= Mod) val -= Mod;
        return val;
    }
};

int main() {
    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    RollingHash rh(S);

    unsigned long long T_hashed = 0;
    for (int i = 0; i < T.size(); i++) {
        T_hashed += rh.mulMod(T[i], rh.getPow(M - i - 1));
    }
    
    vector<int> loc;
    for (int i = 0; i <= N - M; i++) {
        if (rh.get(i, i + M) == T_hashed) 
            loc.push_back(i);
    }
    
    cout << loc.size() << endl;

    for (int i = 0; i < loc.size(); i++) {
        cout << loc[i];
        if (i < loc.size() - 1)
            cout << " ";
    }
    cout << endl;

}
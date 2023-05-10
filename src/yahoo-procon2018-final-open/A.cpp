#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

vector<int> fprime_base(int n) {
    vector<int> r;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;

        int e = 0;
        while (n % i == 0) {
            e++;
            n /= i;
        }
        r.push_back(i);
    }
    if (n != 1) r.push_back(n);
    return r;
}

int popcount(ll x) {
    x -= ((x >> 1) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);
    return x & 0x0000007f;
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> a(N); rep(i, N) cin >> a[i];

    vector<int> cnt(1 << 25);

    rep(i, N) {
        vector<int> base = fprime_base(a[i]);
        for (int bits = 1; bits < (1 << base.size()); bits++) {
            int tmp = 1;
            rep(j, base.size()) {
                if (bits & (1 << j)) tmp *= base[j];
            }
            cnt[tmp]++;
        }
    }

    for (int i = 1; i <= M; i++) {
        int result = 0;
        vector<int> p = fprime_base(i);
        for (int bits = 1; bits < (1 << p.size()); bits++) {
            int t = 1;
            rep(j, p.size()) {
                if (bits & (1 << j)) t *= p[j];
            }
            result += pow(-1, popcount(bits) - 1) * cnt[t];
        }
        cout << N - result << endl;
    }


}
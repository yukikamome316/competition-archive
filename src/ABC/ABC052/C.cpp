#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N;

    modint1000000007 result = 1;
    map<int, int> factorize;
    for (int i = N; i > 0; i--) {
        int base = i;
        for (ll j = 2; j * j <= base; j++) {
            int cnt = 0;
            while (base % j == 0) {
                cnt++;
                base /= j;
            }
            if (cnt != 0) factorize[j] += cnt;
        }
        if (base != 1) factorize[base]++;
    }

    for (auto [p, e] : factorize) {
        result *= e + 1;
    }

    cout << result.val() << endl;

}
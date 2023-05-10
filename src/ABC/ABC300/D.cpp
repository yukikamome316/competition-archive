#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= sqN; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; i * j <= sqN; j += i) {
                is_prime[j] = false;
            }
        }
    }

    ll cnt = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            for (ll k = j + 1; k < N; k++) {
                if (!is_prime[i] || !is_prime[j] || !is_prime[k]) continue;
                ll v = i*i * j * k*k;
            }
        }
    }
    cout << cnt << endl;
}
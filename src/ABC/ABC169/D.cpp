#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;

    vector<pair<ll, ll>> factorize;
    for (ll i = 2; i * i <= N; i++) {
        int cnt = 0;
        while (N % i == 0) {
            cnt++;
            N /= i;
        }
        if (cnt != 0) factorize.push_back({i, cnt});
    }
    if (N != 1) factorize.push_back({N, 1});

    int result = 0;
    for (auto [p, e] : factorize) {
        int e_tmp = 1;
        while (e_tmp * (e_tmp + 1) / 2 <= e) {
            result++, e_tmp++;
        }
    }

    cout << result << endl;
}
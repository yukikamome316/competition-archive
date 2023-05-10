#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    ll C;
    cin >> N >> C;
    vector<ll> dp(N + 1);
    dp[0] = C;
    
    for (int i = 1; i <= N; i++) {
        int T, A; cin >> T >> A;
        if (T == 1) {
            dp[i] = dp[i - 1] &= A;
        } else if (T == 2) {
            dp[i] = dp[i - 1] |= A;
        } else {
            dp[i] = dp[i - 1] ^= A;
        }
        cout << dp[i] << endl;
    }
}
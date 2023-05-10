#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll K; cin >> K;
    vector<int> data(N);
    rep(i, N) cin >> data[i];

    int log_K = 0;
    for (int i = 60; i >= 0; i--) {
        if (K & (1ll << i)) {
            log_K = i;
            break;
        }
    }

    int dp[N][log_K + 1];
    rep(i, N) {
        dp[i][0] = data[i] - 1;
    } 
    
    rep(j, log_K) {
        rep(i, N) {
            dp[i][j + 1] = dp[dp[i][j]][j];
        }
    }

    int now = 0;
    int idx = 0;
    ll k = K;
    while (k) {
        if (k & 1)
            now = dp[now][idx];
        k >>= 1;
        idx++;
    }
    cout << now + 1 << endl;
}
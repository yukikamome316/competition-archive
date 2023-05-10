#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll K; cin >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int log_K = 0;
    for (int i = 60; i >= 0; i--) {
        if (K & (1ll << i)) {
            log_K = i;
            break;
        }
    }
    
    ll dp[N - 1][log_K + 1];
    rep()

}

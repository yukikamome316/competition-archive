#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N; cin >> N;
    vector<int> h(N);
    rep(i, N) {
        cin >> h[i];
    }
    vector<int> dp(N, INFINITY);
    dp[0] = 0, dp[1] = abs(h[1] - h[0]);
    rep2(i, 2, N) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N - 1] << endl;
}
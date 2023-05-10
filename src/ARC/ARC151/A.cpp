#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    string S, T; cin >> S >> T;

    for (ll bit = 0; bit < 1 << N; bit++) {
        string U;
        rep(i, N) {
            if (bit & (1 << i)) U += "1";
            else U += "0";
        }
        reverse(U.begin(), U.end());
        int S_distance = 0, T_distance = 0;
        rep(i, N) {
            if (U[i] != S[i]) S_distance++;
        }
        rep(i, N) {
            if (U[i] != T[i]) T_distance++;
        }
        if (S_distance == T_distance) {
            cout << U << endl;
            return 0;
        };
    }
    cout << -1 << endl;

}
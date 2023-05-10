#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<pair<int, int>> E;

    rep(i, N) {
        E.push_back({A[i], 2 * (i + 1)});
        E.push_back({A[i], 2 * (i + 1) + 1});
    }
    rep2(k, 1, 2 * N + 2) {
        int now = k;
        int depth = 0;
        while (now != 1) {
            rep(i, E.size()) {
                if (E[i].second != now) continue;
                now = E[i].first;
                depth++;
                break;
            }
        }
        cout << depth << endl;
    }

}
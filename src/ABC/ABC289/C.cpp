#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> a(M);

    rep(i, M) {
        int C; cin >> C;
        rep(j, C) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    int cnt = 0;

    for (int bit = 1; bit < (1 << M); bit++) {
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            bool exists = false;
            for (int j = 0; j < M; j++) {
                if (bit & (1 << j)) {
                    set<int> st(a[j].begin(), a[j].end());
                    if (st.find(i) != st.end()) exists = true;
                }
                if (exists) break;
            }

            if (!exists) ok = false;
        }

        if (ok) cnt++;
    }

    cout << cnt << endl;

}
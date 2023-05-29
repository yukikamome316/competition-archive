#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    while (true) {
        int n, m; cin >> n >> m;
        if (n + m == 0) break;

        vector<int> a(n), w(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> w[i];

        sort(w.begin(), w.end());
        vector<int> w2(2 * m);

        for (int i = 0; i < m; i++) {
            w2[2 * i] = w[i];
            w2[2 * i + 1] = -w[i];
        }

        vector<set<int>> add(n);

        rep(i, n) {
            for (ll bit = 1; bit < (1ll << (2 * m)); bit++) {
                int sum = 0;

                rep(j, 2 * m) {
                    if (bit & (1 << j)) {
                        sum += w2[j];
                    }
                }

                int tmp = abs(a[i] - sum);
                add[i].insert(tmp);
            }
        }

        set<int> result(add[0]);
        rep(i, n) {
            set<int> tmp;
            set_intersection(add[i].begin(), add[i].end(), result.begin(), result.end(), inserter(tmp, tmp.end()));
            result = tmp;
        }

        cout << (result.empty() ? -1 : *result.begin()) << endl;

    }
}
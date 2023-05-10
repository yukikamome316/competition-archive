#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Range Minimum Query (RMQ): https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n, (1ll << 31) - 1);

    int k = sqrt(n);
    vector<int> bucket(floor((n - 1) / k) + 1, (1ll << 31) - 1);
    
    rep(_, q) {
        int com; cin >> com;
        if (com == 0) {
            int idx, x; cin >> idx >> x;
            a[idx] = x;
            bucket[floor(idx / k)] = a[idx];
            rep(i, k) chmin(bucket[floor(idx / k)], a[idx + i * k]);
        } else if (com == 1) {
            int s, t; cin >> s >> t;
            int result = (1ll << 31) - 1;

            for (int i = 0; i < bucket.size(); i++) {
                int l = i * k, r = (i + 1) * k - 1;
                
                if (s <= l && r <= t) chmin(result, bucket[i]);
                else if (s > r || t < l) continue;
                else {
                    for (int j = max(s, l); j <= min(t, r); j++)
                        chmin(result, a[i]);
                }
            }
            cout << result << endl;
        }
    }
}
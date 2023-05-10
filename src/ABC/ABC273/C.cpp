#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> data(N); rep(i, N) cin >> data[i];
    
    vector<ll> b(data);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> ans(N);
    rep(i, data.size()) {
        auto new_itr = upper_bound(b.begin(), b.end(), data[i]);
        ans[distance(new_itr, b.end())]++;
    }
    rep(i, N) cout << ans[i] << endl;
}
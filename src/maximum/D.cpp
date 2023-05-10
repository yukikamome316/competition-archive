#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<int> data(N); rep(i, N) cin >> data[i];

    vector<int> data_cmp(N);
    copy(data.begin(), data.end(), data_cmp.begin());
    sort(data_cmp.begin(), data_cmp.end());
    data_cmp.erase(unique(data_cmp.begin(), data_cmp.end()), data_cmp.end());
    for (int i = 0; i < N; i++) {
        auto new_itr = lower_bound(data_cmp.begin(), data_cmp.end(), data[i]);
        data[i] = distance(data_cmp.begin(), new_itr);
    }

    vector<int> ans(N);
    rep(i, N) ans[i] = i;

    int count = 0;
    int idx = 0;
    while (data != ans) {
        if (data[idx] > data[idx + 1]) {
            int buffer = data[idx];
            data[idx] = data[idx + 1];
            data[idx + 1] = buffer;
            count++;
        }
        idx++;
        if (idx >= N - 1) idx = 0;
    }
    cout << (count <= M ? "Yes" : "No") << endl;
}
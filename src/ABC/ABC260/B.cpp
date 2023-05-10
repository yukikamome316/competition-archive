#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, n, s) for (int i = s; i < n; i++)

typedef long long ll;
using namespace std;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<pair<int, int>> m_data(N);
    vector<pair<int, int>> m_data_sorted(N);
    vector<pair<int, int>> e_data(N);
    vector<pair<int, int>> e_data_sorted(N);
    rep(i, N) {
        int A; cin >> A;
        m_data[i] = {-A, i + 1};
        m_data_sorted[i] = {-A, i + 1};
    }
    rep(i, N) {
        int B; cin >> B;
        e_data[i] = {-B, i + 1};
        e_data_sorted[i] = {-B, i + 1};
    }

    sort(m_data_sorted.begin(), m_data_sorted.end());
    sort(e_data_sorted.begin(), e_data_sorted.end());

    vector<int> passed;
    rep(i, X) {
        passed.emplace_back(m_data_sorted[i].second);
    }
    int count = 0;
    int idx = 0;
    while (count < Y) {
        if (find(passed.begin(), passed.end(), e_data_sorted[idx].second) == passed.end()) {
            passed.emplace_back(e_data_sorted[idx].second);
            idx++;
            count++;
        } else {
            idx++;
        }
    }

    vector<pair<int, int>> sum;
    rep(i, N) {
        if (find(passed.begin(), passed.end(), i + 1) == passed.end()) {
            sum.emplace_back(pair<int, int>(m_data[i].first + e_data[i].first, i + 1));
        }
    }
    sort(sum.begin(), sum.end());
    rep(i, Z) {
        passed.emplace_back(sum[i].second);
    }

    sort(passed.begin(), passed.end());
    rep(i, (int)passed.size()) {
        cout << passed[i] << endl;
    }
}
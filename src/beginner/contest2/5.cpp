#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, L; cin >> N >> L;
    vector<int> data(N);
    rep(i, N) {
        data[i] = L + i;
    }

    int sum_prev = accumulate(data.begin(), data.end(), 0);
    int min_abs = 8000000;
    int result = 0;
    rep(i, N) {
        int sum_next = 0;
        rep(j, N) {
            if (i == j) continue;
            sum_next += data[j];
        }
        if (abs(sum_prev - sum_next) < min_abs) {
            min_abs = abs(sum_prev - sum_next);
            result = sum_next;
        }
    }
    cout << result << endl;
}
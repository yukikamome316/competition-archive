#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    rep(i, T) {
        int N; cin >> N;
        vector<vector<int>> A(T, vector<int>(N));
        vector<vector<int>> B(T, vector<int>(N));
        vector<vector<int>> C(T, vector<int>(N));
        rep(j, N) {
            cin >> A[i][j] >> B[i][j] >> C[i][j];
        }
        vector<int> sum(N);
        rep(j, N) {
            sum[j] = A[i][j] + B[i][j] + C[i][j];
        }
        cout << max_element(sum.begin(), sum.end()) - sum.begin() + 1 << endl;

    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<vector<char>> data(N, vector<char>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> data[i][j];
        }
    }
    rep(i, N) {
        rep(j ,N) {
            if (i == j && data[i][j] != '-') {
                cout << "incorrect" << endl;
                return 0;
            }

            if ((data[i][j] == 'W' && data[j][i] == 'W')
                || (data[i][j] == 'L' && data[j][i] == 'L')
                || (data[i][j] == 'D' && data[j][i] != 'D')) {
                    cout << "incorrect" << endl;
                    return 0;
                }
        }
    }
    cout << "correct" << endl;
}
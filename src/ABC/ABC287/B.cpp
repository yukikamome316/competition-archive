#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    int cnt = 0;
    rep(i, N) {
        string substr = "";
        rep(j, 3) substr += S[i][3 + j];
        rep(j, M) {
            if (substr == T[j]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}
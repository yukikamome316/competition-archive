#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> S(M);
    rep(i, M) {
        int C;
        cin >> C;
        set<int> tmp;
        rep(j, C) {
            int a;
            cin >> a;
            tmp.insert(a);
        }
        S[i] = tmp;
    }

    int cnt = 0;
    for (int bits = 1; bits < (1 << M); bits++) {
        set<int> merged;
        rep(i, M) {
            if (bits & (1 << i)) {
                for (int x : S[i])
                    merged.insert(x);
            }
        }
        if (merged.size() == N) cnt++;
    }

    cout << cnt << endl;
}
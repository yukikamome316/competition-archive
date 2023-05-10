#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repi(i, n, s) for (int i = (int)s; i < (int)n; i++)

typedef long long ll;
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N + 1);
    S[1] = "1";
    repi(i, N + 1, 2) {
        S[i] = S[i - 1] + " " + to_string(i) + " " + S[i - 1];
    }

    cout << S[N] << endl;
}
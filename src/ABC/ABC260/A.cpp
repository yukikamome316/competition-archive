#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, n, s) for (int i = s; i < n; i++)

typedef long long ll;
using namespace std;

int main() {
    string S; cin >> S;
    rep(i, 3) {
        if (count(S.begin(), S.end(), S[i]) == 1) {
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int T = 0, A = 0;
    rep(i, N) {
        if (S[i] == 'T') T++;
        else A++;
    }

    if (T == A) {
        if (S[N - 1] == 'T') T--;
        else A--;
    }

    cout << (T >= A ? "T" : "A") << endl;
    
}
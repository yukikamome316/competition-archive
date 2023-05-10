#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string S; cin >> S;
    int result = 0;
    rep(i, S.size()) {
        if ((i + 1) % 2 == 0)
            result -= S[i] - '0';
        else
            result += S[i] - '0'; 
    }
    cout << result << endl;
}
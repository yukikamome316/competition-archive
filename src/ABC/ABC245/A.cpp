#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    bool ok = false;
    if (A < C) ok = true;
    else if (A == C && B <= D) ok = true;

    cout << (ok ? "Takahashi" : "Aoki") << endl;
}
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    modint998244353 result = 1;
    result *= A;
    result *= B;
    result *= C;
    modint998244353 tmp = 1;
    tmp *= D;
    tmp *= E;
    tmp *= F;
    result -= tmp;
    cout << result.val() << endl;
}
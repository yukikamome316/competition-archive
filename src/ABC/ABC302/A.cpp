#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll A, B; cin >> A >> B;
    if (A % B) cout << A / B + 1 << endl;
    else cout << A / B << endl;
}
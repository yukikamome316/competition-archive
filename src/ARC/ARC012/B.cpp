#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    cout << fixed << setprecision(15);
    int N, va, vb, L;
    cin >> N >> va >> vb >> L;

    double ret = L;
    while (N--) {
        ret = ret / va * vb;
    }
    cout << ret << endl;
}
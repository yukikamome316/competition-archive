#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    if (N % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll result = 0;
    ll tmp = 5;
    while (tmp <= N / 2) {
        result += N / tmp / 2;
        tmp *= 5;
    }
    
    cout << result << endl;

}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    int k = 0;
    ll tmp = N;
    while (tmp != 0) {
        tmp /= 10;
        k++;
    }

    int result = k + 1;
    for (int bits = 1; bits < (1 << k); bits++) {
        int sum = 0;
        string s = to_string(N);
        
        rep(i, k) {
            if (bits & (1 << i))
                sum += s[i] - '0';
        }
        
        if (sum % 3 == 0) {
            result = min(result, k - __builtin_popcount(bits));
        }
    }

    cout << (result == k + 1 ? -1 : result) << endl;
}
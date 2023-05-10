#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    ll sum = accumulate(A.begin(), A.end(), 0ll);
    
    T %= sum;
    int idx = 0;
    int result = -1;
    while (true) {
        if (idx >= N) idx = 0;
        if (T <= A[idx]) {
            break;
        } else {
            T -= A[idx];
            idx++;
        }
    }
    cout << idx + 1 << " " << T << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int bob_sum = 0, alice_sum = 0;
    rep(i, N / 2) {
        alice_sum += a[2 * i];
        bob_sum += a[2 * i + 1];
    }
    if (N % 2 != 0)
        alice_sum += a[N - 1];

    cout << alice_sum - bob_sum << endl;
}

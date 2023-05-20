#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    ll D; cin >> D;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    int x = 0, y = 0;
    ll ans = -1;
    while (x < N && y < M) {
        if (A[x] - B[y] > D) 
            x++;
        else if (B[y] - A[x] > D) 
            y++;
        else {
            ans = A[x] + B[y];
            break;
        }
    }

    cout << ans << endl;
}

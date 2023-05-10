#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> H(N); rep(i, N) cin >> H[N];
    
    vector<pair<int, int>> data(M);
    rep(i, M) {
        int U, V; cin >> U, V;
        data[i] = {U, V};
    }
   
    
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    set<ll> S(A.begin(), A.end());
    vector<pair<ll, ll>> interval;

    ll num = *S.begin();
    for (auto e : S) {
        if (e == *S.begin()) continue;
        if (num + 1 == e) 
    }
    
}
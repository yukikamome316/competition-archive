#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    vector<ll> data(3);
    rep(i, 3) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    if (data[2] - data[1] > data[0])
        cout << -1 << endl;
    else
        cout << data[2] << endl;
}
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> data(N);
    rep(i, N)
        cin >> data[i];

    modint998244353 count = 0;
    for (int bit = 1; bit <= (1 << N); bit++) {
        int num_count = 0;
        rep(i, N) {
            if (bit & (1 << i))
                num_count++;
        }
        if (num_count == 1) {
            count++;
            break;
        }
        modint sum = 0;
        sum.set_mod(num_count); 
        rep(i, N) {
            if (bit & (1 << i)) {
                sum += data[i];
            }
        }
        if (sum.val() == 0) count++;
        
    }
    cout << count.val() << endl;
}
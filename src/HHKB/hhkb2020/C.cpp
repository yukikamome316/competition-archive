#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> p(N); rep(i, N) cin >> p[i];
    vector<bool> flags(N + 1);

    int result = 0;
    rep(i, N) {
        flags[p[i]] = true;
        while (flags[result]) result++;
        cout << result << endl;
    }
    
}
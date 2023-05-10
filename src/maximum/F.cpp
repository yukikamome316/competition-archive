#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    map<int, int> counted;
    cout << 1 << endl;
    counted[1] = 1;
    while (true) {
        int a; cin >> a;
        if (!a) break;
        counted[a] = 1;
        if (counted.find(0) == counted.end()) break;
        rep2(i, 1, N + 1) {
            if (!counted[i]) {
                cout << i << endl;
                counted[i] = 1;
                break;
            }
        }
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int n, h, w; cin >> n >> h >> w;
    int count = 0;
    rep(i, n) {
        int h_i, w_i; cin >> h_i >> w_i;
        if (h_i >= h && w_i >= w) count++;
    }
    cout << count << endl;
}
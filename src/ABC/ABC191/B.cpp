#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> data(N);
    rep(i, N) {
        cin >> data[i];
    }
    rep(i, N) {
        if (data[i] == X) continue;
        cout << data[i];
        if (i == N - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    
}
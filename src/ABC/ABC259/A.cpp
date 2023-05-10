#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    if (X <= M) {
        cout << T << endl;
    } else {
        cout << T - D * (X - M) << endl;
    }
}
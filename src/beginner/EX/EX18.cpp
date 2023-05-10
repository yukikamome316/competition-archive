#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A.at(i) >> B.at(i);
    }

    vector vec2(N, vector<char>(N, '-'));
    
    rep(i, M) {
        vec2[A[i] - 1][B[i] - 1] = 'o';
        vec2[B[i] - 1][A[i] - 1] = 'x';
    }

    rep(i, N) {
        rep(j, N) {
            cout << vec2[i][j];
            if (j != N - 1) cout << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    rep(i, N - 1) {
        if (abs(A[i] - A[i + 1]) == 1) {
            cout << A[i] << " ";
            continue;
        }

        if (A[i] < A[i + 1]) {
            cout << A[i] << " ";
            rep(j, A[i + 1] - A[i] - 1) {
                cout << A[i] + j + 1 << " ";
            }
        } else {
            cout << A[i] << " ";
            rep(j, A[i] - A[i + 1] - 1) {
                cout << A[i] - j - 1 << " ";
            }
        }
    }

    cout << A[N - 1] << endl;
    
}
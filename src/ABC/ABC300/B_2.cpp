#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int H, W; cin >> H >> W;

    vector<string> A(H);
    vector<string> B(H);

    rep(i, H) cin >> A[i];
    rep(i, H) cin >> B[i];

    rep(i, H) {
        vector<string> B_swapped(B);
        iter_swap(B_swapped.begin(), B_swapped.begin() + H - 1);
        for (int j = 0; j < H - 2; j++) {
            iter_swap(B_swapped.rbegin() + j, B_swapped.rbegin() + j + 1);
        }

        int idx = 0;
        while (idx <= W) {
            rep(k, H) {
                rep(_, idx) {
                    swap(B_swapped[k][0], B_swapped[k][W - 1]);
                    for (int j = 0; j < H - 2; j++) {
                        swap(B_swapped[k][W - j - 1], B_swapped[k][W - j - 2]);
                    }
                }
            }
            
            if (A == B_swapped) {
                cout << "Yes" << endl;
                return 0;
            }
            idx++;
        }
        
    }

    cout << "No" << endl;
}
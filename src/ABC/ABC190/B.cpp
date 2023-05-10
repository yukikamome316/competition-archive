#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int N, S, D;
    cin >> N >> S >> D;
    /*
     * N: 呪文の種類
     * S: 詠唱の時間制限
     * D: 最低ダメージ
     */
    bool result = false;
    rep(i, N) {
        int X, Y; // X: 秒数, Y: 威力
        cin >> X >> Y;
        if (X < S && Y > D) {
            result = true;
        }
    }
    cout << (result ? "Yes" : "No") << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int tmp = -1;
    rep(i, 101) {
        if (i >= A && i <= B && i >= C && i <= D) tmp++;
    }
    cout << (tmp > 0 ? tmp : 0) << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    if (S[0] >= 'A' && S[0] <= 'Z'
        && S[7] >= 'A' && S[7] <= 'Z') {
        bool flag = false;
        rep(i, 6) {
            if (i == 0) {
                if(S[i + 1] < '1' || S[i + 1] > '9') {
                    flag = true;
                    break;
                }
            } else {
                if(S[i + 1] < '0' || S[i + 1] > '9') {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;

    } else {
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    vector<string> S(9); rep(i, 9) cin >> S[i];
    
    int result = 0;
    for (int a = 1; a <= 9; a++) {
        for (int x_idx = 0; x_idx < 9 - a; x_idx++) {
            for (int y_idx = 0; y_idx < 9 - a; y_idx++) {
                if (S[y_idx][x_idx] == '#'
                    && S[y_idx][x_idx + a] == '#'
                    && S[y_idx + a][x_idx] == '#'
                    && S[y_idx + a][x_idx + a] == '#')
                    result++;
            }
        }
    }
    cout << result << endl;
}
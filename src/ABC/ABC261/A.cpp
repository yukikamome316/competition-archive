#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int L_1, R_1, L_2, R_2;
    cin >> L_1 >> R_1 >> L_2 >> R_2;
    int length_1 = R_1 - L_1, length_2 = R_2 - L_2;
    int result = -1;
    if (length_1 > length_2) {
        swap(L_1, L_2);
        swap(R_1, R_2);
    }

    if (R_1 <= L_2) result = 0;
    else if (L_1 <= L_2 && L_2 <= R_1) result = R_1 - L_2;
    else if (L_2 <= L_1 && R_1 <= R_2) result = R_1 - L_1;
    else if (L_1 <= R_2 && R_2 <= R_1) result = R_2 - L_1;
    else result = 0;
    
    cout << result << endl;
}
// TLE

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string S, T; cin >> S >> T;
    
    bool result = false;
    if (S == T) {
        result = true;
    } else {
        int idx = 0;
        while (true) {
            if (S == T) {
                result = true;
                break;
            }
            if (S[idx] == T[idx]) {
                idx++;
                continue;
            }
            bool flag = false;
            int count = 0;
            for (int i = idx - 1; i >= -1; i--) {
                if (i < 0) {
                    flag = true;
                    break;
                }
                if (T[idx] == S[i])
                    count++;
                if (count >= 2) {
                    rep(j, idx - i - 1) {
                       S.insert(S.begin() + i, S[i]); 
                    }
                    break;
                }
                
            }
            if (flag) break;
        }
    }

    cout << (result ? "Yes" : "No") << endl; 
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (!n) break;
        vector<string> data(n);
        rep(i, n) {
            cin >> data[i];
        }
            
        rep(i, n) {
            vector<int> vec = {5, 7, 5, 7, 7};
            int c = 0;
            bool flag = false;
            for (int j = i; j < n; j++) {
                vec[c] -= data[j].size();
                if (vec[4] == 0) {
                    cout << i + 1 << endl;
                    flag = true;
                    break;
                }
                if (vec[c] == 0) {
                    c++;
                    continue;
                }
            }
            if (flag) break;
        }
    }
}
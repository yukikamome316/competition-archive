#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> v(n);
        rep(i, n) {
            cin >> v[i];
        }
        int count = 0;
        for (int j = 1; j < n - 1; j++) {
            if (v[j] > v[j - 1] && v[j] > v[j + 1]) {
                count++;
            }
        }
        cout << count << endl;
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n + m == 0) break;
        vector<int> data(n, 0);
        rep(i, n) {
            cin >> data[i];
        }
        int index = 0;
        int max = 0;
        while (index < n) {
            for (int i = 0; i < n; i++) {
                if (index == i) continue;
                int buffer = data[index] + data[i];
                if (buffer <= m && buffer > max) {
                    max = buffer;
                }
                
            }
            index++;
        }

        if (max == 0) {
            cout << "NONE" << endl;
        } else {
            cout << max << endl;
        }
    }
    
}
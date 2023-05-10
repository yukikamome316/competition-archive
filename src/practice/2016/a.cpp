#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> data(n);
        rep(i, n) {
            cin >> data[i];
        }
        int result = abs(data[1] - data[0]);
        for(int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int buffer = abs(data[i] - data[j]);
                if (buffer < result) {
                    result = buffer;
                }
            }
        }
        cout << result << endl;
    }
}
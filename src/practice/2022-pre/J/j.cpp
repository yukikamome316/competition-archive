#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<int> data(n);
        rep(i, n) {
            cin >> data[i];
        }
        cout << *max_element(data.begin(), data.end()) << endl;
    }
}
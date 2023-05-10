#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    vector<int> vec(5);
    rep(i, 5) {
        cin >> vec[i];
    }
    
    rep(i, 4) {
        if (vec[i] == vec[i + 1]) {
            cout << "YES" << endl;
            return 0;
            
        }
    }
    cout << "NO" << endl;
    return 0;
}
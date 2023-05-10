#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    rep(i, n) {
        cin >> vec[i];
    }
    int ave = accumulate(vec.begin(), vec.end(), 0) / n;

    rep(i, n) {
        cout << abs(ave - vec[i]) << endl;
    }

}
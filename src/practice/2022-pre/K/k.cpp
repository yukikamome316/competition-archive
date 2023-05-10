#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();
    rep(i, n) {
        string line;
        getline(cin, line);
        cout << line.size() << endl;
    }
}
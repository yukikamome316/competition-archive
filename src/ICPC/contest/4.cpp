#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int n; cin >> n;
    string result;
    if (n == 100) {
        result = "Perfect";
    } else if (n >= 90) {
        result = "Great";
    } else if (n >= 60) {
        result = "Good";
    } else {
        result = "Bad";
    }
    cout << result << endl;
}
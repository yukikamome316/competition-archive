#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    while (true) {
        string a, b;
        cin >> a;
        if (a == ".") break;
        cin >> b;

        if (a == b) {
            cout << "IDENTICAL" << endl;
            continue;
        }

        bool is_different = false;
        if (count(a.begin(), a.end(), '\"') 
            != count(b.begin(), b.end(), '\"')) {
            is_different = true;
        }

        int idx_a = 0,
            idx_b = 0,
            count = 0;
        bool is_reading = false;

        while (idx_a < a.size() && idx_b < b.size()) {
            if (!is_reading) {
                if (a[idx_a] != b[idx_b]) {
                    is_different = true;
                    break;
                }
                if (a[idx_a] == '"') {
                    is_reading = true;
                }
            } else {
                if (a[idx_a] != b[idx_b]) {
                    count++;
                    while (a[idx_a] != '"') idx_a++;
                    while (b[idx_b] != '"') idx_b++;
                }
            }

            if (count > 1) {
                is_different = true;
                break;
            }
            idx_a++, idx_b++;
        }

        if (is_different) {
            cout << "DIFFERENT" << endl;
        } else {
            cout << "CLOSE" << endl;
        }
    }
}
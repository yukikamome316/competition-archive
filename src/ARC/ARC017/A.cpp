#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    bool is_prime = true;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            is_prime = false;
            break;
        }
    }
    cout << (is_prime ? "YES" : "NO") << endl;
}
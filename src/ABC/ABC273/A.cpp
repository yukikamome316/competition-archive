#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int f(int n) {
    if (n == 0) return 1;
    else return n * f(n - 1);
}

int main() {
    int N; cin >> N;
    cout << f(N) << endl;
}
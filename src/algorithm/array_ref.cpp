#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    cout << *(*(a + 1)+1) << endl;
}
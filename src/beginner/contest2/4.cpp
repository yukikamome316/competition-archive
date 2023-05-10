#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int A, B; cin >> A >> B;
    vector<int> data = {1, 2, 3};
    data.erase(find(data.begin(), data.end(), A));
    data.erase(find(data.begin(), data.end(), B));
    cout << data[0] << endl;
}
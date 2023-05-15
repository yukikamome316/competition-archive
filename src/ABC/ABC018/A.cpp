#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> data(3); rep(i, 3) cin >> data[i];

    vector<int> sorted(data.begin(), data.end());
    sort(sorted.begin(), sorted.end());

    rep(i, 3) {
        auto itr = find(sorted.begin(), sorted.end(), data[i]);
        cout << 3 - distance(sorted.begin(), itr) << endl;
    }
}
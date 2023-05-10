#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> b(N);
    copy(a.begin(), a.end(), b.begin());
    sort(b.begin(), b.end());
    // b = {1, 3, 4, 6}
    // a = {3, 1, 0, 0, 2}
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < a.size(); i++) {
        auto new_itr = lower_bound(b.begin(), b.end(), a[i]);
        a[i] = distance(b.begin(), new_itr);
    }
    for (int i = 0; i < N; i++)
        cout << a[i] << endl;

}
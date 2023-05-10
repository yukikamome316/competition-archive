#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    set<set<int>> E;
    rep(i, M) {
        int U, V; cin >> U >>V;
        E.insert({U, V});
    }
    ll count = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            for (int c = b + 1; c <= N; c++) {
                set<int> buf1 = {a, b};
                set<int> buf2 = {b, c};
                set<int> buf3 = {c, a};
                if (E.find(buf1) != E.end()
                    && E.find(buf2) != E.end()
                    && E.find(buf3) != E.end())
                    count++;
            }
        }
    }

    cout << count << endl;
}
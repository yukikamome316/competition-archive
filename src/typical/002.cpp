#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<string> result;
    rep(i, 1 << N) {
        int depth = 0;
        string S;
        bool flag = false;
        rep(j, N) {
            if (i & (1 << j)) {
                depth++;
                S += "(";
            } else {
                depth--;
                S += ")";
            }
            if (depth < 0) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        if (!depth) 
            result.emplace_back(S);
    }

    sort(result.begin(), result.end());
    for (string &str : result)
        cout << str << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    string ans = "atcoder";
    vector<int> S_num(ans.size());
    vector<int> ans_num(ans.size());
    rep(i, ans.size()) ans_num[i] = i;

    rep(i, S.size()) {
        S_num[i] = find(ans.begin(), ans.end(), S[i]) - ans.begin();
    }
    int count = 0;
    int idx = 0;
    while (S_num != ans_num) {
        if (idx >= S_num.size()) idx = 0;
        if (S_num[idx] > S_num[idx + 1]) {
            swap(S_num[idx], S_num[idx + 1]);
            count++;
        }
        idx++;
    }
    cout << count << endl;
}
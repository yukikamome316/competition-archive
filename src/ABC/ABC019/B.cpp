#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string str;
    cin >> str;
    // ランレングス圧縮
    vector<pair<char, int>> rle;
    rle.push_back({str[0], 0});
    for (int i = 0; i < str.size(); i++) {
        if (rle.back().first == str[i]) {
            rle.back().second++;
        } else {
            rle.push_back({str[i], 1});
        }
    }
    for (int i = 0; i < rle.size(); i++) {
        cout << rle[i].first << rle[i].second;
    }
    cout << endl;

}

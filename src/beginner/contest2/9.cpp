#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    int length = 0;
    int first = 0;
    rep(i, N) {
        int buffer; cin >> buffer;
        if (i == 0) {
            first = buffer;
        }
        length += abs(buffer);
    }
    if ((first > 0 && M > 0) || (first < 0 && M < 0)) {
        length -= M;
    } else if ((first > 0 && M < 0) || (first < 0 && M > 0)) {
        length += M;
    }
    cout << length << endl;
}
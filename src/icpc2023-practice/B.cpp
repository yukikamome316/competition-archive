#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    while (true) {
        int h, w; cin >> h >> w;
        if (h + w == 0) break;

        vector<string> keyboard(h);
        rep(i, h) cin >> keyboard[i];

        string str; cin >> str;

        int cnt = 0;
        int x = 0, y = 0;

        rep(i, str.size()) {
            rep(j, h) {
                rep(k, w) {
                    if (keyboard[j][k] != str[i]) continue;
                    cnt += abs(j - y) + abs(k - x);
                    y = j, x = k;
                }
            }
            cnt++;
        }

        cout << cnt << endl;
    }
}
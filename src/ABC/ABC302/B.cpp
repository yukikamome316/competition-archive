#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W; cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];
    
    string words = "snuke";
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};

    auto isValidPos = [&](pair<int, int> pos) {
        if (pos.first >= 0 && pos.first < H
            && pos.second >= 0 && pos.second < W) return true;
        return false;
    };

    rep(i, H) rep(j, W) {
        if (grid[i][j] != 's') continue;

        rep(k, 8) {
            string s = "s";
            rep2(l, 1, 5) {
                pair<int, int> v = {i + dy[k] * l, j + dx[k] * l};
                
                if (!isValidPos(v)) break;
                s += grid[v.first][v.second];
            }
            if (s == words) {
                rep(l, 5) {
                    cout << i + dy[k] * l + 1 << " " << j + dx[k] * l + 1 << endl;
                }  
                return 0;
            }
        }
    }

}
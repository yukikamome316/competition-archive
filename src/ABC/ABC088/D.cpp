#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int H, W; cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    int sx = 0, sy = 0;
    vector dist(H, vector<int>(W, -1));
    dist[sx][sy] = 0;
    queue<pair<int, int>> que;
    que.push({sx, sy});

    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        if (i > 0 && grid[i - 1][j] != '#' && dist[i - 1][j] == -1) {
            dist[i - 1][j] = dist[i][j] + 1;
            que.push({i - 1, j});
        }
        if (i < H - 1 && grid[i + 1][j] != '#' && dist[i + 1][j] == -1) {
            dist[i + 1][j] = dist[i][j] + 1;
            que.push({i + 1, j});
        }
        if (j > 0 && grid[i][j - 1] != '#' && dist[i][j - 1] == -1) {
            dist[i][j - 1] = dist[i][j] + 1;
            que.push({i, j - 1});
        }
        if (j < W - 1 && grid[i][j + 1] != '#' && dist[i][j + 1] == -1) {
            dist[i][j + 1] = dist[i][j] + 1;
            que.push({i, j + 1});
        }
    }

    int black_count = 0;
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') black_count++;
        }
    }
    if (dist[H - 1][W - 1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << H * W - (dist[H - 1][W - 1] + 1) - black_count << endl;
    

}
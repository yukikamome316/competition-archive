#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int R, C, sy, sx, gy, gx;
    cin >> R >> C >> sy >> sx >> gy >> gx;

    vector board(R + 1, vector<char>(C + 1));
    rep2(i, 1, R + 1) {
        rep2(j, 1, C + 1) {
            cin >> board[i][j];
        }
    }

    vector dist(R + 1, vector<int>(C + 1, -1));
    queue<pair<int, int>> que;
    que.push({sy, sx});

    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0};

    dist[sy][sx] = 0;
    
    while (!que.empty()) {
        pair<int, int> v = que.front();
        que.pop();

        rep(i, 4) {
            int py = v.first + dy[i];
            int px = v.second + dx[i];

            if (py >= 1 && px >= 1 && py <= R && px <= C) {
                if (dist[py][px] != -1 || board[py][px] == '#') continue;
            
                dist[py][px] = dist[v.first][v.second] + 1;
                que.push({py, px});
            }
        }
    }

    cout << dist[gy][gx] << endl;
    
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    vector graph(N, vector<bool>(N, false));

    rep(i, Q) {
        int num; cin >> num;
        if (num == 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a][b] = true;
        } else if (num == 2) {
            int a; cin >> a;
            a--;
            rep(j, N) {
                if (graph[j][a]) graph[a][j] = true;
            }
        } else {
            int a; cin >> a;
            a--;
            vector<bool> can_follow(N, false);
            rep(j, N) {
                if (a == j) continue;
                if (graph[a][j]) {
                    rep(k, N) {
                        if (a == k) continue;
                        if (graph[j][k]) can_follow[k] = true;
                    }
                }
            }
            rep(j, N) {
                if (can_follow[j]) graph[a][j] = true;
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            cout << (graph[i][j] ? "Y" : "N");
        }
        cout << endl;
    }
    
}
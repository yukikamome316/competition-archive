#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector graph(N, vector<bool>(N, false));
    
    rep(i, M) {
        int A, B; cin >> A >> B;
        A--, B--;
        graph[A][B] = true;
        graph[B][A] = true;
    }


    rep(i, N) {
        vector<bool> is_checked(N, false);
        int cnt = 0;
        rep(j, N) {
            if (i == j) continue;
            if (graph[i][j]) {
                rep(k, N) {
                    if (j == k || i == k) continue;
                    if (graph[i][k]) continue;
                    if (graph[j][k] && !is_checked[k]) {
                        cnt++;
                        is_checked[k] = true;
                    }
                }
            }
        }
        cout << cnt << endl;
    }

}
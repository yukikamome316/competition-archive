#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int f(int dep, vector<int> A, int M, vector<vector<int>> data) {
    if (dep == 0) {
        int point = 0;
        rep(i, data.size()) {
            if (A[data[i][1]] - A[data[i][0]] == data[i][2])
                point += data[i][3];
        }
        return point;
    }

    int lastA;
    int point = 0;
    if (A.empty()) lastA = 1;
    else lastA = A.back();

    for (int i = lastA; i <= M; i++) {
        vector<int> tmpA = A;
        tmpA.push_back(i);
        point = max(point, f(dep - 1, tmpA, M, data));
    }
    return point;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector data(Q, vector<int>(4));
    rep(i, Q) {
        rep(j, 4) {
            cin >> data[i][j];
        }
    }
    
    cout << f(N, {}, M, data) << endl;
}
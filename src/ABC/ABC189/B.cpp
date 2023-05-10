#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int N, X; 
    cin >> N >> X;
    int count = -1;
    int sum = 0; // doubleを回避
    rep(i, N) {
        int V, P;
        cin >> V >> P;
        sum += V * P;
        if (sum > X * 100) { // doubleを回避するために100倍
            count = i + 1;
            break;
        }
    }
    cout << count << endl;
}
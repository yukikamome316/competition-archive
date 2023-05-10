#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N;
    int s_x, s_y, t_x, t_y;
    cin >> N >> s_x >> s_y >> t_x >> t_y;
    map<tuple<int, int>, int> data;
    rep(i, N) {
        int buffer_x, buffer_y;
        cin >> buffer_x >> buffer_y;
        tuple<int, int> buffer(buffer_x, buffer_y);
        cin >> data[buffer]; // r_i
    }

    
    
}
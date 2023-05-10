#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int f(int x) {
    string lt_str = to_string(x);
    sort(lt_str.begin(), lt_str.end());
    string gt_str = lt_str;
    reverse(gt_str.begin(), gt_str.end());
    return stoi(gt_str) - stoi(lt_str);
}

int calc(int N, int K) {
    if (K == 0) return N;
    return f(calc(N, K - 1));
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << calc(N, K) << endl;
}
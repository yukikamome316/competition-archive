#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> data(N);
    rep(i, N) cin >> data[i];
    double ave = (double)accumulate(data.begin(), data.end(), 0) / N;
    double buf = 0.0;
    rep(i, N) {
        buf += (data[i]-ave)*(data[i]-ave);
    }
    buf /= N;
    double ss = sqrt(buf);
    cout << *max_element(data.begin(), data.end()) << endl;
    cout << *min_element(data.begin(), data.end()) << endl;
    cout << (int)ave << endl;
    cout << std::fixed << setprecision(10) << ss << endl;
    cout << (fmod(ss, 100.0) == 0.0 ? "Yes" : "No") << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    if (N <= pow(10, 3) - 1) {
      cout << N << endl;
      return 0;
    }

    rep(i, 6) {
      if (N >= pow(10, i + 3) && N <= pow(10, i + 4) - 1) {
        cout << N - (N % (int)pow(10, i + 1)) << endl;
        return 0;
      }
    }
}
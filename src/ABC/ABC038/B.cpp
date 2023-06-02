#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int result = 0;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        int num = i;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        if (sum >= A && sum <= B) result += i;
    }

    cout << result << endl;
}
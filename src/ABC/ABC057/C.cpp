#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

ll getDigit(ll num){
	ll digit = 0;
	while (num != 0){
		num /= 10;
		digit++;
	}
	return digit;
}

int main() {
    ll N; cin >> N;
    vector<ll> divisors = {1, N};
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            divisors.push_back(i);
            if (i * i != N) divisors.push_back(N / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    vector<ll> results;
    if (divisors.size() % 2 == 0) {
         for (auto it = divisors.begin(); it != divisors.begin() + divisors.size() / 2; it++) {
            results.push_back(getDigit(*(divisors.rbegin() + (it - divisors.begin()))));
         }
    } else {
        for (auto it = divisors.begin(); it != divisors.begin() + divisors.size() / 2 + 1; it++) {
            results.push_back(getDigit(*(divisors.rbegin() + (it - divisors.begin()))));
        }
    }
    cout << *min_element(results.begin(), results.end()) << endl;
}
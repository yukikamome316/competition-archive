#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;

  cin >> N;
  priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int>> pq_greater;
  ll ac = 0;
  rep(i, N) {
    int tmp;
    cin >> tmp;
    ac += tmp;
    pq.push(tmp);
    pq_greater.push(tmp);
  }

  int mean = ac / N;

  ll ans = 0;
  rep(i, N / 2) {
    int max_val = pq.top();
    int min_val = pq_greater.top();
    pq.pop();
    pq_greater.pop();

    if (abs(max_val - min_val) <= 1) break;
    ans += max_val - mean;
  }

  cout << max(0ll, ans - 1) << endl;
}
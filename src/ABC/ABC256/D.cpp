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
  vector<pair<int, int>> data(N);
  rep(i, N) {
    int L, R;
    cin >> L >> R;
    data[i] = {L, R};
  }

  sort(data.begin(), data.end());

  int left = data[0].first;
  rep(i, N - 1) {
    if (data[i].second < data[i + 1].first) {
      cout << left << " " << data[i].second << endl;
      left = data[i + 1].first;
    }
  }
  cout << left << " " << data[N - 1].second << endl;
}
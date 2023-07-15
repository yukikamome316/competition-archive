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
  vector<string> fi(N);
  rep(i, N) {
    cin >> fi[i];
  }

  int state = 0;
  char current = fi[0][0];
  pair<int, int> pos = {0, 0};
  while (true) {
    if (state == 0) {
      pos.second++;
      if (pos.second >= N) {
        pos.second--;
        state++;
        continue;
      }
    }
    if (state == 1) {
      pos.first++;
      if (pos.first >= N) {
        pos.first--;
        state++;
        continue;
      }
    }
    if (state == 2) {
      pos.second--;
      if (pos.second < 0) {
        pos.second++;
        state++;
        continue;
      }
    }
    if (state == 3) {
      pos.first--;
      if (pos.first < 0) {
        pos.first++;
        break;
      }
    }

    int tmp = current;
    current = fi[pos.first][pos.second];
    fi[pos.first][pos.second] = tmp;
  }

  rep(i, N) {
    cout << fi[i] << endl;
  }
}
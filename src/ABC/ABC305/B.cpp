#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> dist = {3, 1, 4, 1, 5, 9, 0};
  char p, q;
  cin >> p >> q;

  int result = 0;

  if (p == q) {
    result = 0;
  } else if (p < q) {
    rep2(i, p - 'A', q - 'A') {
      result += dist[i];
    }
  } else {
    rep2(i, q - 'A', p - 'A') {
      result += dist[i];
    }
  }

  cout << result << endl;
}
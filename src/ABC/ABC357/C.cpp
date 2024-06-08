#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<char>> generate_carpet(int k) {
  if (k == 0) {
    vector<vector<char>> carpet(1, vector<char>(1, '#'));
    return carpet;
  }

  int three_pow = 1;
  rep(i, k) {
    three_pow *= 3;
  }

  vector<vector<char>> carpet(three_pow, vector<char>(three_pow, '#'));

  vector<vector<char>> sub_carpet = generate_carpet(k - 1);

  int block_size = three_pow / 3;

  for (int i = 0; i < carpet.size(); i++) {
    for (int j = 0; j < carpet[i].size(); j++) {
      carpet[i][j] = sub_carpet[i % block_size][j % block_size];
    }
  }

  for (int i = block_size; i < 2 * block_size; i++) {
    for (int j = block_size; j < 2 * block_size; j++) {
      carpet[i][j] = '.';
    }
  }

  return carpet;
}

int main() {
  int n;
  cin >> n;
  auto ans = generate_carpet(n);
  
  rep(i, ans.size()) {
    rep(j, ans[i].size()) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}

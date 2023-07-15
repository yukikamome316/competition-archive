#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool check(vector<string> &fi, int &H, int &W) {
  rep(i, H) {
    bool del = true;
    rep(j, W) {
      if (fi[i][j] == '#')
        del = false;
    }

    if (del) {
      // 行を消すときは、一番後ろに挿入して高さを1つ減らす
      for (int j = i; j < H - 1; j++) {
        swap(fi[j], fi[j + 1]);
      }
      H--;
      return true;
    }
  }

  rep(i, W) {
    bool del = true;
    rep(j, H) {
      if (fi[j][i] == '#')
        del = false;
    }

    if (del) {
      // 列の削除はsubstrを使う
      rep(j, H) {
        // (j, i)が消すべき座標であるから、それ以外のマスを取得して代入
        fi[j] = fi[j].substr(0, i) + fi[j].substr(i + 1);
      }
      W--;
      return true;
    }
  }

  return false;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> fi(H);
  rep(i, H) cin >> fi[i];

  // 消せなくなるまで繰り返す
  while (check(fi, H, W));

  rep(i, H) {
    rep(j, W) {
      cout << fi[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
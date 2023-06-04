#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  rep2(i, 1, N + 1) cin >> a[i];

  int current = 1;
  int cnt = 0;
  // ボタンを押したとき、その行先は1つしかない
  // ループしない限り高々N回以内の遷移で終了するはず (N <= 10^5)
  // とりあえず 10^6 回試してみる
  rep(i, 1000000) {
    current = a[current];
    cnt++;
    if (current == 2) {
      cout << cnt << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
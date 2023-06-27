// 1: 1 (0)
// 2: 2 1 (1) +1
// 3: 3 1 2 (3) +2
// 4: 4 1 2 3 (6) +3
// 5: 5 1 2 3 4 (10) +4
// 6: 6 1 2 3 4 5 (15) +5
// 7: 7 1 2 3 4 5 6 (21) +6
// 8: 8 1 2 3 4 5 6 7 (28) +7
// 9: 9 1 2 3 4 5 6 7 8 (36) +8
// 10: 10 1 2 3 4 5 6 7 8 9 (45) +9
//
// 実験したら N * (N - 1) / 2 っぽい

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  // オーバーフローに注意
  ll N;
  cin >> N;
  cout << N * (N - 1) / 2 << endl;
}
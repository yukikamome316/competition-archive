#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  // 最大値を2で割っていけば、全体として最小になる
  // 割られて一番小さくなれるのは最大値
  // 最大値を高速に取得するために、優先度付きキューを用いる
  priority_queue<int> que;
  rep(i, N) {
    int tmp;
    cin >> tmp;
    que.push(tmp);
  }

  while (M--) {
    int x = que.top();
    que.pop();
    que.push(x / 2);
  }

  ll sum = 0;
  while (!que.empty()) {
    sum += que.top();
    que.pop();
  }

  cout << sum << endl;
}
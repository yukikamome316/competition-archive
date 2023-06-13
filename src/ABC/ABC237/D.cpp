#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  deque<int> dq;
  dq.push_back(N);
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == 'L')
      dq.push_back(i);
    else
      dq.push_front(i);
  }

  rep(i, N + 1) {
    cout << dq.front() << " ";
    dq.pop_front();
  }

  // クエリを逆から処理する。5がRで挿入されたのならば、4は5の左にあった。
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int nand(int x, int y) {
  if (x == 0 && y == 0) return 1;
  if ((x == 0 && y == 1) || (x == 1 && y == 0)) return 1;
  return 0;
}

int f(int i, int j, string S) {
  if (i == j) return S[i] - '0';
  if (i < j) return nand(f(i, j - 1, S), S[j] - '0');
  return 0;
}

int calc(string S, int N) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      sum += f(i, j, S);
    }
  }
  return sum;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  cout << calc(S, N) << endl;
}
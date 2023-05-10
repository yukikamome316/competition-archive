// syoch's submission: https://atcoder.jp/contests/arc151/submissions/35754615
#include <iostream>
#include <string>
using namespace std;

#define out cout
#define in cin

// #define DEBUG

#ifdef DEBUG
#define dout cout
#define din(x, d) x = d
#else
#define dout \
  if (0) cout
#define din(x, d) cin >> x
#endif

const int popcount(string x) {
  int count = 0;
  for (int i = 0; i < x.length(); i++) {
    if (x[i] == '1') {
      count++;
    }
  }
  return count;
}

const int HDistance(string a, string b) {
  int x = 0;
  for (int i = 0; i < a.size(); i++) {
    x += (a[i] != b[i]);
  }
  return x;
}

int main(int argc, char const *argv[]) {
  int N;
  string S;
  string T;

  din(N, 5);
  din(S, "00100");
  din(T, "10011");

  if ((popcount(S) + popcount(T)) & 1 == 1) {
    out << -1 << endl;
    return 0;
  }

  string U;
  for (int i = 0; i < N; i++) {
    U += '0';
  }

  int d_S = popcount(S), d_T = popcount(T);
  if (d_S == d_T) {
    out << U << endl;
    return 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    dout << i << ": "
         << "T: " << T << "[" << d_T << "]>" << T[i] << ", "
         << "S: " << S << "[" << d_S << "]>" << S[i] << ", "
         << "U: " << U << ">" << U[i] << endl;

    if (S[i] == T[i]) continue;

    if (d_S < d_T) {
      dout << "S < T" << endl;
      if (U[i] != T[i]) {
        U[i] = T[i];
        d_S += 1;
        d_T -= 1;
      }
    } else {
      dout << "S > T" << endl;
      if (U[i] != S[i]) {
        U[i] = S[i];
        d_T += 1;
        d_S -= 1;
      }
    }
    if (d_S == d_T) {
      out << U << endl;
      return 0;
    }
  }
  out << -1 << endl;

  return 0;
}

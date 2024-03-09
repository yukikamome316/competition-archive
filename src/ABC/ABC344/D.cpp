#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++) // 繰り返しのためのマクロ
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++) // 開始位置を指定して繰り返しのためのマクロ
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { // より大きい値が見つかった場合に値を更新する関数
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template<class T> inline bool chmin(T& a, T b) { // より小さい値が見つかった場合に値を更新する関数
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  string T;
  cin >> T; // ターゲット文字列を入力する
  int N;
  cin >> N; // バッグの数を入力する

  vector<vector<string>> S(N, vector<string>()); // 各バッグに含まれる文字列を格納するための2次元ベクトルを作成する

  rep(i, N) {
    int A;
    cin >> A; // バッグiに含まれる文字列の数を入力する
    S[i].resize(A); // バッグiに含まれる文字列を格納するためのベクトルのサイズを変更する
    rep(j, A) {
      cin >> S[i][j]; // バッグiに含まれる文字列を入力する
    }
  }

  vector<vector<int>> dp(N + 1, vector<int>(T.size() + 1, INT_MAX)); // 最小選択回数を格納するための2次元ベクトルを作成する
  dp[0][0] = 0; // 空のバッグと空のターゲット文字列の最小選択回数を初期化する

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= T.size(); j++) {
      if (dp[i - 1][j] != INT_MAX) {
        // 何もしない

        chmin(dp[i][j], dp[i - 1][j]); // バッグiから文字列を選ばない場合の最小選択回数を更新する

        // バッグiから文字列を選ぶ
        for (int k = 0; k < S[i - 1].size(); k++) {
          int len = S[i - 1][k].size(); // 選ばれた文字列の長さを取得する
          if (j + len <= T.size() && T.substr(j, len) == S[i - 1][k]) { // 選ばれた文字列がターゲット文字列の部分文字列と一致するかをチェックする
            chmin(dp[i][j + len], dp[i - 1][j] + 1); // 選ばれた文字列が有効な場合、最小選択回数を更新する
          }
        }
      }
    }
  }

  int ans = dp[N][T.size()]; // ターゲット文字列全体の最小選択回数を取得する
  cout << (ans == INT_MAX ? -1 : ans) << endl; // 最小選択回数を出力する。選択が不可能な場合は-1を出力する
}

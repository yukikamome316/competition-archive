#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

bool isValidPos(pair<int, int> pos, vector<string> fi, int H, int W) {
  return (pos.first >= 0 && pos.first < H
        && pos.second >= 0 && pos.second < W
        && fi[pos.first][pos.second] != '#');
}

bool dfs(pair<int, int> pos, pair<int, int> gpos, vector<vector<bool>>& visited, vector<string>& fi, int H, int W) {  
  visited[pos.first][pos.second] = true;
  if (pos == gpos) return true;

  rep(dir, 4) {
    pair<int, int> new_pos = {
      pos.first + dx[dir], pos.second + dy[dir]
    };

    if (isValidPos(new_pos, fi, H, W) 
      && !visited[new_pos.first][new_pos.second] ) {
      return dfs(new_pos, gpos, visited, fi, H, W);
    }
  }

  return false;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> fi(H);
  rep(i, H) {
    cin >> fi[i];
  }

  pair<int, int> spos, gpos;

  rep(i, H) {
    rep(j, W) {
      if (fi[i][j] == 's') spos = {i, j};
      else if (fi[i][j] == 'g') gpos = {i, j};
    }
  }

  vector<vector<bool>> visited(H, vector<bool>(W));
  cout << (dfs(spos, gpos, visited, fi, H, W) ? "Yes" : "No") << endl;
}
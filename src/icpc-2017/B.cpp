#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

enum class eResult{
  IDENTICAL,
  CLOSE,
  DIFFERENT
};

int main() {
  while (true) {
    string s1, s2;
    cin >> s1;
    if (s1 == ".") break;
    cin >> s2;

    size_t s1Len = s1.size();
    size_t s2Len = s2.size();

    int s1Idx = 0, s2Idx = 0;
    bool isConstStr = false;
    eResult ret = eResult::IDENTICAL;

    while (s1Idx < s1Len && s2Idx < s2Len) {
      if (s1[s1Idx] == '"') {
        isConstStr ^= true;
        s1Idx++;
        continue;
      } else if (s2[s2Idx] == '"') {
        isConstStr ^= true;
        s1Idx++;
        continue;
      }

      if (s1[s1Idx] != s2[s2Idx] && !isConstStr) {
        ret = eResult::DIFFERENT;
        break;
      } else if (s1[s1Idx] != s2[s2Idx] && isConstStr) {
        // TODO: implement this!!!
      }

      s1Idx++, s2Idx++;
    }
  }
}

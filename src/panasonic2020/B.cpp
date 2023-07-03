#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  if (H == 1 || W == 1) {
    cout << 1 << endl;
  } else {
    cout << (ll)ceil((double)H * W / 2) << endl;
  }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  deque<int> deq;
  rep(i, n) {
    if (i % 2 == 0)
      deq.push_back(a[i]);
      else deq.push_front(a[i]);
  }

  rep(i, n) {
    if (0 < i)
      cout << " ";
        
    int x;
    if (n % 2 == 0) x = deq.front(), deq.pop_front();
    else x = deq.back(), deq.pop_back();
    cout << x << endl;
  }

  cout << endl;
}
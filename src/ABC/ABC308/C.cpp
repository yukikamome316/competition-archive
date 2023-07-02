#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

bool compare(const pair<long double, int>& a, const pair<long double, int>& b) {
  long double doubleA = a.first;
  long double doubleB = b.first;
  if (doubleA != doubleB) {
    return doubleA > doubleB;
  }
  return a.second < b.second;
}

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> data(N);
  rep(i, N) {
    ll A, B;
    cin >> A >> B;
    data[i] = {A, B};
  }

  vector<pair<long double, int>> score(N);
  rep(i, N) {
    score[i] = {(long double)data[i].first / (data[i].first + data[i].second), i};
  }

  sort(score.begin(), score.end(), compare);

  rep(i, N) {
    cout << score[i].second + 1 << " ";
  }

  cout << endl;
}
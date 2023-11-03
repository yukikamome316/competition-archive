#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// string toBin(long long num) {
//   std::string binary = "";
//   for (int i = 63; i >= 0; --i) {
//     binary += (num & (1LL << i)) ? '1' : '0';
//   }
//   return binary;
// }

map<ll, int> makeBitSumSubset(vector<int> a) {
  map<ll, int> mp;
  if (a.size() == 0) return mp;

  rep(bits, 1ll << (int)a.size()) {
    ll sum = 0;
    rep(i, a.size()) {
      if (bits & (1ll << i)) {
        sum += a[i];
      } else {
        sum -= a[i];
      }
    }

    mp[sum] = bits;
  }
  
  return mp;
}

enum class DIR {
  R, D, L, U
};

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> ax(N / 2), ay(N - N / 2);
  rep(i, N) {
    if (i % 2) cin >> ax[i / 2];
    else cin >> ay[i / 2];
  }

  vector<int> axl(ax.begin(), ax.begin() + ax.size() / 2),
              axr(ax.begin() + ax.size() / 2, ax.end()),
              ayl(ay.begin(), ay.begin() + ay.size() / 2),
              ayr(ay.begin() + ay.size() / 2, ay.end());

  map<ll, int> axls = makeBitSumSubset(axl), 
               axrs = makeBitSumSubset(axr), 
               ayls = makeBitSumSubset(ayl),
               ayrs = makeBitSumSubset(ayr);

  // X
  bool found_x = false;
  ll found_x_bits = 0;
  for (auto [val, bits] : axrs) {
    ll search_val = X - val;
    if (axls.contains(search_val)) {
      found_x = true;
      found_x_bits = bits;
      found_x_bits <<= axl.size();
      found_x_bits += axls[search_val];
    }
  }

  // Y
  bool found_y = false;
  ll found_y_bits = 0;
  for (auto [val, bits] : ayrs) {
    ll search_val = Y - val;
    if (ayls.contains(search_val)) {
      found_y = true;
      found_y_bits = bits;
      found_y_bits <<= ayl.size();
      found_y_bits += ayls[search_val];
    }
  }

  if (!found_x || !found_y ) {
    cout << "No" << endl;
    return 0;
  }

  string op = "";
  DIR dir = DIR::R;
  rep(i, N) {
    if (i % 2) {
      // Y
      rep(j, N - N / 2) {
        if (found_y_bits & (1ll << j)) {
          if (dir == DIR::R) {
            op += 'L';
          } else if (dir == DIR::L) {
            op += 'R';
          }
          dir = DIR::U;
        } else {
          if (dir == DIR::R) {
            op += 'R';
          } else if (dir == DIR::L) {
            op += 'L';
          }
          dir = DIR::D;
        }
      }
    } else {
      // X
      rep(j, N / 2) {
        if (found_x_bits & (1ll << j)) {
          if (dir == DIR::U) {
            op += 'R';
          } else if (dir == DIR::D) {
            op += 'L';
          }
          dir = DIR::R;
        } else {
          if (dir == DIR::U) {
            op += 'L';
          } else if (dir == DIR::D) {
            op += 'R';
          }
          dir = DIR::L;
        }
      }
    }
  }
  
  cout << op << endl;
}
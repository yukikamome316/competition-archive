#pragma GCC Optimize("O3")

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;

class Vec3 {
 public:
  ll x, y, z;

  Vec3() : x(0), y(0), z(0) {}
  Vec3(ll x, ll y, ll z) : x(x), y(y), z(z) {}

  ll dot(Vec3 v) { return this->x * v.x + this->y * v.y + this->z * v.z; }

  Vec3 operator+(const Vec3 &v) {
    return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
  }

  Vec3 operator-(const Vec3 &v) {
    return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
  }

  Vec3 operator-() { return Vec3(-this->x, -this->y, -this->z); }

  bool operator==(const Vec3 &v) const {
    return (this->x == v.x) && (this->y == v.y) && (this->z == v.z);
  }

  bool operator!=(const Vec3 &v) const { return !(*this == v); }

  bool operator<(const Vec3 &v) const {
    if (this->x == v.x) {
      if (this->y == v.y) {
        return this->z < v.z;
      }
      return this->y < v.y;
    }

    return this->x < v.x;
  }

  bool operator>(const Vec3 &v) const { return !(*this < v) && (*this != v); }
};

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<Vec3> data(n);
    rep(i, n) {
      int x, y, z;
      cin >> x >> y >> z;
      data[i] = Vec3(x, y, z);
    }

    set<Vec3> st(data.begin(), data.end());

    int cnt = 0;
    rep(i, n) {
      rep(j, n) {
        rep(k, n) {
          if (i == j || j == k || k == i) continue;

          // iを基準に計算
          ll i_dot = (data[j] - data[i]).dot(data[k] - data[i]);
          if (i_dot != 0) continue;

          Vec3 newVertex = data[j] + data[k] - data[i];
          if (st.contains(newVertex)) {
            cnt++;
          }
        }
      }
    }

    cout << cnt / 8 << endl;
  }
}

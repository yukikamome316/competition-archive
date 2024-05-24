#include <bits/stdc++.h>
using namespace std;

int euclid(int a, int b) {
    return (a % b) ? euclid(b, a % b): b;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << euclid(d, euclid(c, euclid(a, b)));
}
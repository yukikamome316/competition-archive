#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

struct modint {
    int value;
    int base;

    modint(long long v, int b) : 
        value(v % b), base(b) {}
    
    modint operator+(int right) {
        value += right % base;
        value %= base;  
    }
    
    modint operator+(modint right) {
        value += 
    }
}

int main() {
    int N, M, P; cin >> N >> M >> P;
    
}
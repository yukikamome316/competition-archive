#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)n; i++)
using namespace std;
using ll = long long;

class Parser {
    using State = string::const_iterator;
    string data;
    State itr;
    pair<string, int> result;

    int num() {
        int ret = 0;
        while (isdigit(*itr)) {
            ret *= 10;
            ret += *itr - '0';
            itr++;
        }
        return ret;
    }

    int term() {
        int ret = num();
        while (true) {
            char op = *itr;
            if (op == '+') {
                itr++;
                ret += num();
            } else if (op == '-') {
                itr++;
                ret -= num();
            } else {
                break;
            }
        }
        return ret;
    }

    int formula() {
        int ret = 0;
        itr++;
        ret += term();
        itr++;
        while (true) {
            if (*itr == '*') {
                itr += 2;
                ret *= term();
                itr++;
            } else if (*itr == '/') {
                itr += 2;
                ret /= term();
                itr++;
            } else {
                break;
            }
        }
        return ret;
    }

public:
    Parser(string data) {
        this->data = data;
        itr = this->data.begin();
        result.second = formula();
    }

    string getRPN() {
        return result.first;
    }

    int getValue() {
        return result.second;
    }
};

int main() {
    int T; cin >> T;
    rep(i, T) {
        string s; cin >> s;
        cout << Parser(s).getValue() << endl;
    }
}

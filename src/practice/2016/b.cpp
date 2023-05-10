#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (!n) break;

        vector<char> data(n);
        rep(i, n) {
            cin >> data[i];
        }
        vector<char> represents;
        rep(i, n) {
            if (!count(represents.begin(), represents.end(), data[i])) {
                represents.emplace_back(data[i]);
            }
        }
        vector<int> counts(represents.size());
        
        int d = -1;
        char who;

        rep(i, n) {
            auto it = find(represents.begin(), represents.end(), data[i]);
            counts[it - represents.begin()]++;

            auto max_it = max_element(counts.begin(), counts.end());
            auto max_idx = max_it - counts.begin();
            
            bool duplicated = false;
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < j; k++) {
                    if (counts[j] == *max_it && counts[k] == *max_it) {
                        duplicated = true;
                        break;
                    }
                }
                if (duplicated) break;
            }
            if (duplicated) continue;

            int rest = n - (i + 1);
            vector<bool> flags(represents.size(), false);
            rep(j, represents.size()) {
                if (max_idx == j) {
                    flags[j] = true;
                }
                if (counts[j] + rest < *max_it) {
                    flags[j] = true;
                }
            }
            bool exist = false;
            rep(j, counts.size()) {
                if (flags[j] == false) {
                    exist = true;
                }
            }
            if (!exist) {
                d = i + 1;
                who = represents[max_idx];
                break;
            }
        }
        

        if (d >= 0) {
            cout << who << " " << d << endl;
        } else {
            cout << "TIE" << endl;
        }

    }
}
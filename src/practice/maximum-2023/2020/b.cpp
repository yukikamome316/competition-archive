#include <bits/stdc++.h>
using namespace std;

int counter(vector<int> vec) {
    int count = 0;
    for (int i = 0; i < vec.size() - 3; i++) {
        if (vec[i] != 2) continue;
        if (vec[i + 1] == 0
            && vec[i + 2] == 2
            && vec[i + 3] == 0) ++count;
    }
    return count;
}

int main() {
    vector<vector<int>> vec;

    while (true) {
        int n = 0;
        cin >> n;
        if (n == 0) {
            for (int i = 0; i < vec.size(); i++) {
                cout << counter(vec[i]) << endl;
            }
            return 0;
        }
        
        vector<int> num;
        for (int i = 0; i < n; i++) {
            int buffer = 0;
            cin >> buffer;
            num.emplace_back(buffer);
        }
        vec.emplace_back(num);
    }
}

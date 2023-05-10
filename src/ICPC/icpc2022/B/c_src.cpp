#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    while (true) {
        int n; cin >> n;
        if (!n) break;
        map<int, vector<int>> data;
        rep(i, n) {
            int buffer1, buffer2; cin >> buffer1 >> buffer2;
            data[i + 1].emplace_back(buffer1);
            data[i + 1].emplace_back(buffer2);
        }

        int counter = 0;
        while (1) {
            int prev_idx = 1;
            int next_idx = 2;
            bool flag = false;
            while (1) {
                rep(i, n) {
                    if (data[i + 1].size() != 0) {
                        rep(j, n) {
                            if (count(data[i + 1].begin(), data[i + 1].end(), j + 1) >= 2) {
                                data[i + 1].erase(find(data[i + 1].begin(), data[i + 1].end(), j + 1));
                                data[i + 1].erase(find(data[i + 1].begin(), data[i + 1].end(), j + 1));
                            }
                        }
                    }
                }
                if (prev_idx > 0) {
                    prev_idx = n;
                }
                if (next_idx <= 0) {
                    next_idx = n;
                }
                while (1) {
                    if (prev_idx == next_idx) {
                        flag = true;
                        break;
                    }
                    if (data[prev_idx].size() == 0) {
                        prev_idx--;
                        if (prev_idx <= 0) {
                            prev_idx = n;
                        }
                    } else {
                        break;
                    }
                }

                if (flag) break;
                
                auto min_it = min_element(data[prev_idx].begin(), data[prev_idx].end());
                data[next_idx].emplace_back(*min_it);
                data[prev_idx].erase(min_it);
                counter++;
                prev_idx++, next_idx++;
                    
                while (1) {
                    if (next_idx > n) 
                        next_idx = 1;
                    if (prev_idx == next_idx) {
                        flag = true;
                        break;
                    }
                    if (data[next_idx].size() == 0) {
                        next_idx++;
                        if (next_idx > n) 
                            next_idx = 1;
                    } else {
                        break;
                    }
                }
                if (flag) break;

            }

            if (flag) break;
        }

        cout << counter << endl;
    }
}
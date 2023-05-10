#include <bits/stdc++.h>
using namespace std;

int calcMax(vector<vector<int>> data, int count) {
    vector<int> sum;
    for (int i = 0; i < count; i++) {
        int counter = 0;
        for (int j = 0; j < data.size(); j++) {
            counter += data[j][i];
        }
        sum.emplace_back(counter);
    }
    return *max_element(sum.begin(), sum.end());
}

int main() {
    while (true) {
        vector<vector<int>> data;
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }

        for (int i = 0; i < m; i++) {
            vector<int> buffer1;
            for (int j = 0; j < n; j++) {
                int buffer2 = 0;
                cin >> buffer2;
                buffer1.emplace_back(buffer2);
            }
            data.emplace_back(buffer1);
        }
        cout << calcMax(data, n) << endl;

    }
}

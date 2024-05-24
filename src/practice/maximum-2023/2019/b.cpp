#include <bits/stdc++.h>
using namespace std;

int count(map<char, pair<int, int>> keyboard, string text) {
    int result = keyboard[text[0]].first + keyboard[text[0]].second + 1;
    for (int i = 0; i < text.size() - 1; i++) {
        result += abs(keyboard[text[i]].first - keyboard[text[i + 1]].first) 
                    + abs(keyboard[text[i]].second - keyboard[text[i + 1]].second);
        result++;
    }
    return result;
}

int main() {
    while(true) {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) {
            return 0;
        }

        map<char, pair<int, int>> keyboard;
        for (int i = 0; i < h; i++) {
            string buffer;
            cin >> buffer;
            for (int j = 0; j < w; j++) {
                keyboard[buffer[j]] = make_pair(i, j);
            }
        }

        string text;
        cin >> text;
        cout << count(keyboard, text) << endl;
    }
}
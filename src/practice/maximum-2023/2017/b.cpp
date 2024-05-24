#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector<string> getCStrings(string str) {
    vector<string> vec;
    int found_e_loc = 0;
    
    while (found_e_loc + 1 < str.size()) {
        bool exist = false;
        int s_loc, e_loc;
        
        for (int i = found_e_loc; i < str.size(); i++) {
            if (exist) break;
            if (str[i] == '"') {
                s_loc = i;
                for (int j = i + 1; j < str.size(); j++) {
                    if (str[j] == '"') {
                        e_loc = j;
                        found_e_loc = j + 1;
                        exist = true;
                        break;
                    }
                } 
            }
        }

        if (!exist) return vec;
        string buffer;
        for (int i = s_loc; i <= e_loc; i++) {
            buffer += str[i];
        }
        vec.push_back(buffer);
    }
    
    return vec;
}

int main() {
    while (true) {
        string a, b;
        cin >> a;
        if (a == ".") break;
        cin >> b;
        if (a == b) {
            cout << "IDENTICAL" << endl;
            continue;
        }
        vector vec_a = getCStrings(a);
        vector vec_b = getCStrings(b);

        string a_cut_str, b_cut_str;
        int a_offset = 0,
            b_offset = 0;

        for (string str : vec_a) {
            int s = a.find(str, a_offset); // what
        }

        bool is_different = false;
        if (vec_a.size() != vec_b.size() 
            || vec_a.size() + vec_b.size() == 0
            || a_cut_str != b_cut_str) {
            is_different = true;
        } else {
            int count = 0;
            for (int i = 0; i < vec_a.size(); i++) {
                if (vec_a[i] != vec_b[i]) count++;
            }
            if (count > 1) {
                is_different = true;
            }
        }

        if (is_different) {
            cout << "DIFFERENT" << endl;
        } else {
            cout << "CLOSE" << endl;
        }

    }
}
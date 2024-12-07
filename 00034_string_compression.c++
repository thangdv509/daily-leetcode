#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<char> chars;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;
    
    for(int i = 0; i < n; ++i) {
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch) {
            count ++;
            i++;
        }

        if(count == 1) {
            chars[idx++] = ch;
        } else {
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig : str) {
                chars[idx++] = dig;
            }
        }

        i--;
    }
    chars.resize(idx);
    return idx;
}

int main() {
    string line;
    getline(cin, line);
    vector<char> chars(line.begin(), line.end());

    cout << compress(chars) << endl;

    return 1;
}

// 443. String Compression
// Leetcode 75: 07/12/2024 - Medium
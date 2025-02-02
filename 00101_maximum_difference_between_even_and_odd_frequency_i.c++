#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;

void init() {
    cin >> s;
}

int maxDifference(string s) {
    int max_odd = -1e9;
    int min_even = 1e9;
    int n = s.size();
    int count[26] = {0};

    for(int i = 0; i < n; ++i) {
        int idx = s[i] - 'a';
        count[idx] ++;
    }

    for(int i = 0; i < 26; ++i) {
        if(count[i] % 2 == 0 && count[i] != 0) min_even = min(min_even, count[i]);
        else max_odd = max(max_odd, count[i]);
    }

    return max_odd - min_even;
}

int main() {
    init();

    cout << maxDifference(s) << endl;

    return 0;
}

// 3442. Maximum Difference Between Even and Odd Frequency I
// Weekly Contest 435: 01/02/2025 - Easy
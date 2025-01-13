#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;

void init() {
    cin >> s;
}

int minimumLength(string s) {
    vector<int> charFrequency(26, 0);
    int totalLength = 0;

    for(char curChar : s) charFrequency[curChar - 'a']++;

    for(int frequency : charFrequency) {
        if(frequency == 0) continue;
        else if(frequency % 2 == 0) totalLength += 2;
        else totalLength += 1;
    }

    return totalLength;
}

int main() {
    init();

    cout << minimumLength(s) << endl;

    return 0;
}

// 3223. Minimum Length of String After Operations
// Daily question: 13/01/2025 - Medium
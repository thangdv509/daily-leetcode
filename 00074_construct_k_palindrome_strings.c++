#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string s;
int k;

void init() {
    cin >> s;
    cin >> k;
}

bool canConstruct(string s, int k) {
    if(s.size() < k) return false;

    int letterCount[26] = {0};

    for(char& c : s) letterCount[c-'a']++;

    int oddCount = 0;

    for(int count : letterCount) oddCount += count % 2;

    return oddCount <= k;
}

int main() {
    init();

    cout << canConstruct(s, k);

    return 0;
}

// 1400. Construct K Palindrome Strings
// Daily question: 11/01/2025 - Medium
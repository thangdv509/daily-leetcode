#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;

void init() {
    cin >> s;
}

string clearDigits(string s) {
    int digitCount = 0;
    int n = s.size();
    string res = "";
    
    for(int i = n - 1; i >= 0; --i) {
        if(isdigit(s[i])) digitCount++;
        else {
            if(digitCount == 0) res = s[i] + res;
            else digitCount -= 1;
        }
    }
    
    return res;
}

int main() {
    init();

    cout << clearDigits(s) << endl;

    return 0;
}

// 3174. Clear Digits
// Daily question: 10/02/2025 - Easy
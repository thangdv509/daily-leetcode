#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;
string part;

void init() {
    cin >> s >> part;
}

string removeOccurrences(string s, string part) {
    while(s.length()>0 && s.length()>s.find(part)){
       s.erase(s.find(part),part.length());
    }
    return s;
}

int main() {
    init();

    cout << removeOccurrences(s, part) << endl;

    return 0;
}

// 1910. Remove All Occurrences of a Substring
// Daily question: 11/02/2025 - Medium


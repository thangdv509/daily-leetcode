#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> words;
string pref;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    string word;
    while(ss >> word) words.push_back(word);

    cin >> pref;
}

int prefixCount(vector<string>& words, string pref) {
    int n = pref.size();
    int res = 0;

    for(string word : words) {
        if(word.substr(0, n) == pref) res++;
    }

    return res;
}

int main() {
    init();

    cout << prefixCount(words, pref) << endl;

    return 0;
}

// 2185. Counting Words With a Given Prefix
// Daily question: 09/01/2025 - Easy
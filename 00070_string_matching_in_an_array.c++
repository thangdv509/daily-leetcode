#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> words;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    string word;
    while(ss >> word) words.push_back(word);
}

vector<string> stringMatching(vector<string>& words) {
    int n = words.size();
    vector<string> res;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j && words[j].find(words[i]) != string::npos) {
                res.push_back(words[i]);
                break;
            }
        }
    }

    return res;
}

int main() {
    init();

    vector<string> res = stringMatching(words);

    for(string word : words) cout << word << " ";

    return 0;
}

// 1408. String Matching in an Array
// Daily question: 07/01/2025 - Easy



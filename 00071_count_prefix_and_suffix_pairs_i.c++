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


bool isPrefixAndSuffix(const string& str1, const string& str2) {
    int n1 = str1.size(), n2 = str2.size();
    if(n1 > n2) return false;
    return str2.substr(0, n1) == str1 && str2.substr(n2-n1) == str1;
}

int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size(), count = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(isPrefixAndSuffix(words[i], words[j])) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    init();

    cout << countPrefixSuffixPairs(words) << endl;

    return 0;
}

// 3042. Count Prefix and Suffix Pairs I
// Daily question: 08/01/2025 - Easy


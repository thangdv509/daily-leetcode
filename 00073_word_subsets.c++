#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> mainWords;
vector<string> requiredWords;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    string mainWord;
    while(ss >> mainWord) mainWords.push_back(mainWord);

    getline(cin, line);
    istringstream ss2 (line);
    string requiredWord;
    while(ss2 >> requiredWord) requiredWords.push_back(requiredWord);
}

vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
    int maxCharFreq[26] = {0};
    int tempCharFreq[26];

    for(const auto& word : requiredWords) {
        memset(tempCharFreq, 0, sizeof(tempCharFreq));
        for(char ch : word) tempCharFreq[ch-'a']++;
        for(int i = 0; i < 26; ++i) maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
    }

    vector<string> universalWords;

    for (const auto& word : mainWords) {
        memset(tempCharFreq, 0, sizeof tempCharFreq);
        for (char ch : word) {
            tempCharFreq[ch - 'a']++;
        }
        bool isUniversal = true;
        for (int i = 0; i < 26; ++i) {
            if (maxCharFreq[i] > tempCharFreq[i]) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) {
            universalWords.emplace_back(word);
        }
    }
        
    return universalWords;
}

int main() {
    init();

    vector<string> res = wordSubsets(mainWords, requiredWords);

    return 0;
}

// 916. Word Subsets
// Daily question: 10/01/2025 - Medium
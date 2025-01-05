#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string s;

void init() {
    cin >> s;
}

char getMirror(char c) {
    return 'z' - (c - 'a');
}

long long calculateScore(string s) {
    int n = s.size();
    vector<bool> marked(n, false); 
    unordered_map<char, vector<int>> mirrorPositions; 
    long long score = 0;
    
    for (int i = 0; i < n; ++i) {
        char currentMirror = getMirror(s[i]);
    
        if (mirrorPositions.count(currentMirror)) {
            auto &positions = mirrorPositions[currentMirror];
            while (!positions.empty() && marked[positions.back()]) {
                positions.pop_back();
            }
    
            if (!positions.empty()) {
                int j = positions.back();
                marked[i] = true;
                marked[j] = true;
                score += (i - j);
                positions.pop_back();
            }
        }
    
        mirrorPositions[s[i]].push_back(i);
    }
    
    return score;
}

int main() {
    init();
    
    cout << calculateScore(s) << endl;

    return 0;
}

// Q2. Find Mirror Score of a String
// Weekly Contest 431: 04/01/2025 - Medium 
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std; 

int mod = 1e9 + 7;
int freq[26][1000] = {{0}};

int dp[1001][1001];
vector<string> words;
string target;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    string temp;
    while (ss >> temp) words.push_back(temp);

    cin >> target;
}


int f(int i, int j, const vector<string>& words, const string& target) {
    if(j == 0) return 1;
    if(i < 0 || i < j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    long long cnt = 0;

    cnt += f(i-1, j, words, target);

    long long fc = freq[target[j-1] - 'a'][i-1];

    if(fc > 0) cnt += f(i-1, j-1, words, target)*fc;

    dp[i][j] = cnt%mod;

    return dp[i][j];
}

int numWays(vector<string>& words, const string& target) {
    const int m = target.size();
    int n = words[0].size();

    memset(freq, 0, sizeof(freq));

    for(int i = 0; i < n; ++i) {
        for(const auto& w : words) freq[w[i]-'a'][i]++;
    }

    memset(dp, -1, sizeof(dp));

    return f(n, m, words, target);
}

// 1639. Number of Ways to Form a Target String Given a Dictionary
// Daily question: 29/12/2024 - Hard  
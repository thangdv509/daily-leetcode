#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void backtrack(const string s, int start, vector<string> path, vector<vector<string> >& result, const vector<vector<bool> > dp) {
    if (start == s.length()) {
        result.push_back(path);
        return;
    }

    for (int end = start; end < s.length(); ++end) {
        if (dp[start][end]) {
            path.push_back(s.substr(start, end - start + 1));

            backtrack(s, end + 1, path, result, dp);

            path.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    int n = s.length();
    vector<vector<bool> > dp(n, vector<bool>(n, false));

    for(int i = 0; i < n; ++i) {
        dp[i][i] = true;
    } 

    for(int len = 2; len <= n; ++ len) {
        for(int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if(s[i] == s[j] && (len == 2 || dp[i+1][j-1])) dp[i][j] = true;
        }
    }
    vector<vector<string> > res;
    vector<string> path;
    backtrack(s, 0, path, res, dp);
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<vector<string> > res = partition(s);
    for(int i = 0; i < res[0].size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
        
// 131. Palindrome Partitioning
// Daily question: 27/11/2024 - Medium
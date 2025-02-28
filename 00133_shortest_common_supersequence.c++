#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string str1, str2;

void init() {
    cin >> str1 >> str2;
}

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    

    int i = m, j = n;
    string result = "";
    
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) { 
            result.push_back(str1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            result.push_back(str1[i - 1]);
            i--;
        } else {
            result.push_back(str2[j - 1]);
            j--;
        }
    }
    
    while (i > 0) {
        result.push_back(str1[i - 1]);
        i--;
    }
    
    while (j > 0) {
        result.push_back(str2[j - 1]);
        j--;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    init();

    cout << shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}

// 2467. Most Profitable Path in a Tree
// Daily question: 28/02/2025 - Hard
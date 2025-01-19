#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

int MOD = 1e9 + 7;
vector<int> nums;
int k;
vector<vector<int>> memo;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);

    cin >> k;
}

int C(int k, int n) {
    if(k > n) return 0;
    if(k == 0 || k == n) return 1;
    if(memo[k][n] != -1) return memo[k][n];
    return memo[k][n] = (C(k-1, n-1) + C(k, n-1)) % MOD;
}

int minMaxSums(vector<int>&nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    memo.assign(k + 1, vector<int>(n+1, -1));

    long long res = 0;
    
    for(int i = 0; i < n; ++i) {
        long long maxContrib = 1;
        long long minContrib = 1;
        
        for(int j = 2; j <= k; ++j) {
            maxContrib = (maxContrib + C(j-1, i)) % MOD;
            minContrib = (minContrib + C(j-1, n-1-i)) % MOD;
        }

        res = (res + nums[i] * (maxContrib + minContrib) % MOD) % MOD;
    }

    return res;
}

int main() {
    init();

    cout << minMaxSums(nums, k) << endl; 

    return 0;
}

// 3428. Maximum and Minimum Sums of at Most Size K Subsequences
// Weekly Contest 433: 19/01/2025 - Medium
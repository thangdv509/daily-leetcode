#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
int target;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while (ss >> num) nums.push_back(num);

    cin >> target;
}

int findTargetSumWays(vector<int>& nums, int target) {
    const int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int diff = sum - target; 

    if(diff < 0 || diff % 2 != 0) return 0;

    diff /= 2;

    int dp[21][2001] = {{0}};

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int sum = 0; sum <= diff; ++sum) {
            dp[i][sum] = dp[i][sum];

            if (sum >= nums[i-1]) {
                dp[i][sum]+=dp[i-1][sum-nums[i-1]];
            }
        }
    }

    return dp[n][diff];
}

int main () {
    init();

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}

// 494. Target Sum
// Daily question: 26/12/2024 - Medium 
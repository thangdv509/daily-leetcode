#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
}

int maxAscendingSum(vector<int>& nums) {
    int res = 0;
    int curSum = nums[0];
    int n = nums.size();

    for(int i = 1; i < n; ++i) {
        if(nums[i] > nums[i-1]) curSum += nums[i];
        else {
            res = max(curSum, res);
            curSum = nums[i];
        }
    }

    return max(curSum, res);
}

int main() {
    init();

    cout << maxAscendingSum(nums) << endl;

    return 0;
}

// 1800. Maximum Ascending Subarray Sum
// Daily question: 04/02/2025 - Easy
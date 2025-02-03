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

int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int increLength = 1;
    int decreLength = 1;
    int res = 1;

    for(int i = 1; i < n; ++i) {
        if(nums[i] > nums[i-1]) {
            increLength += 1;
            res = max(increLength, res);
        } else increLength = 1;

        if(nums[i] < nums[i-1]) {
            decreLength += 1;
            res = max(decreLength, res);
        } else decreLength = 1;
    }

    return res;
}

int main() {
    init();

    cout << longestMonotonicSubarray(nums) << endl;

    return 0;
}

// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// Daily question: 03/02/2025 - Easy
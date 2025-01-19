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

int subarraySum(vector<int>& nums) {
    int n = nums.size();
    vector<int> preffixSum(n+1, 0);

    for(int i = 0; i < n; ++i) preffixSum[i+1] = preffixSum[i] + nums[i];

    int res = 0;

    for(int i = 0; i < n; ++i) {
        int start = max(0, i - nums[i]);
        int curSum = preffixSum[i+1] - preffixSum[start];
        res += curSum;
    }

    return res;
}

int main() {
    init();

    cout << subarraySum(nums) << endl; 

    return 0;
}

// 3427. Sum of Variable Length Subarrays
// Weekly Contest 433: 19/01/2025 - Easy
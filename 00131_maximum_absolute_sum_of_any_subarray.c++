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

int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0, minSum = 0, maxSum = 0;
    for (int num : nums) {
        sum += num;
        if (sum > maxSum) maxSum = sum;
        if (sum < minSum) minSum = sum;
    }
    return abs(maxSum - minSum);
}

int main() {
    init();

    cout << maxAbsoluteSum(nums) << endl;

    return 0;
}

// 1749. Maximum Absolute Sum of Any Subarray
// Daily question: 26/02/2025 - Mediums
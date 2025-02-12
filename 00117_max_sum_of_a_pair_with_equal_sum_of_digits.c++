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

int maximumSum(vector<int>& nums) {
    int n = nums.size();
    int res = -1;
    unordered_map<int, int> mp;

    for(int i = 0; i < n; ++i) {
        int totalDigit = 0;
        int temp = nums[i];
        
        while(temp != 0) {
            int remain = temp % 10;
            totalDigit += remain;
            temp /= 10;
        }
        
        if(mp.find(totalDigit) != mp.end()) {
            res = max(res, mp[totalDigit] + nums[i]);
            mp[totalDigit] = max(mp[totalDigit], nums[i]);
        }
        else {
            mp[totalDigit] = nums[i];
        }
    }

    return res;
}

int main() {
    init();

    cout << maximumSum(nums) << endl;

    return 0;
}

// 2342. Max Sum of a Pair With Equal Sum of Digits
// Daily question: 12/02/2025 - Medium
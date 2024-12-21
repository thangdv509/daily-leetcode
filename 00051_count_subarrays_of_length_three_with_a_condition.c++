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

int countSubarrays(vector<int>& nums) {
    int res = 0;
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        if (2*(nums[i] + nums[i+2]) == nums[i+1]) res++;
    }

    return res;
};

int main () {
    init();

    cout << countSubarrays(nums) << endl;

    return 0;
}

// Q1.Count Subarrays of Length Three With a Condition
// Biweekly Contest 146: 08/12/2024 - Easy
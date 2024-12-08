#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;

    while(ss >> num) {
        nums.push_back(num);
    }
}

vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;

    for(int i = 0; i < n; ++i) {
        int newIndex = i + nums[i];
        while(newIndex < 0) newIndex += n;
        newIndex %= n;
        res.push_back(nums[newIndex]);
    }

    return res;
}

int main() {
    init();

    vector<int> res = constructTransformedArray(nums);
    
    for(int num : res) {
        cout << num << " ";
    }

    return 1;
}

// 3379. Transformed Array
// Weekly Contest 427: 08/12/2024 - Easy
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


int maximumCount(vector<int>& nums) {
    int pos = 0;
    int zeroCount = 0;
    int n = nums.size();

    for(int i = 0; i < n; ++i) {
        pos++;
        if(nums[i] == 0) zeroCount ++;
        if(nums[i] > 0) {
            pos--;
            break;
        }
    }

    return max(pos-0-zeroCount, n-pos);
}

int main() {
    init();

    cout << maximumCount(nums) << endl;

    return 0;
}

// 2529. Maximum Count of Positive Integer and Negative Integer
// Daily question: 12/03/2025 - Easy
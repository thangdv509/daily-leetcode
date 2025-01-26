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

int countPartitions(vector<int>& nums) {
    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; ++i) {
        if(nums[i] % 2) count ++;
    }

    if(count % 2 == 0) return n - 1; 

    return 0;
}

int main() {
    init();

    cout << countPartitions(nums) << endl;

    return 0;
}

// 3432. Count Partitions with Even Sum Difference
// Weekly Contest 434: 26/01/2025 - Easy
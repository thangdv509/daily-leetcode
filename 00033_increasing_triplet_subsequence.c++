#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

#define max INT_MAX

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

bool increasingTriplet(vector<int>& nums) {
    int min1 = max;
    int min2 = max;

    for(int n : nums) {
        if(n <= min1) min1 = n;
        else if(n <= min2) min2 = n;
        else return true;
    }

    return false;
}

int main() {
    init();
    cout << increasingTriplet(nums) << endl; 

    return 1;
}

// 334. Increasing Triplet Subsequence
// Leetcode 75: 07/12/2024 - Medium
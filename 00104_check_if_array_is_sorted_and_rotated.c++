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

bool check(vector<int>& nums) {
    const int n=nums.size();
    int cntD=0;

    for(int i=1; i<n && cntD<=1; i++){
        if (nums[i]<nums[i-1]) cntD++;
    }

    return (nums[0]>=nums.back() && cntD==1) || cntD==0;
}

int main() {
    init();

    cout << check(nums) << endl;

    return 0;
}

// 1752. Check if Array Is Sorted and Rotated
// Daily question: 02/02/2025 - Easy
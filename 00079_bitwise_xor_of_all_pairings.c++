#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums1, nums2;

void init() {
    string line1;
    getline(cin, line1);
    istringstream ss1 (line1);
    int num1;
    while(ss1 >> num1) nums1.push_back(num1);

    string line2;
    getline(cin, line2);
    istringstream ss2 (line2);
    int num2;
    while(ss2 >> num2) nums2.push_back(num2);
}

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int l1 = nums1.size();
    int l2 = nums2.size();
    int res = 0;

    if(l1 % 2 != 0) for(int num : nums2) res ^= num; 

    if(l2 % 2 != 0) for(int num : nums1) res ^= num;

    return res; 
}

int main() {
    init();

    cout << xorAllNums(nums1, nums2) << endl;

    return 0;
}

// 2425. Bitwise XOR of All Pairings
// Daily question: 16/01/2025 - Medium
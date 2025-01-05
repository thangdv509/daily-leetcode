#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

const long long MOD = 1e9 + 7; 

vector<int> nums;

void init(){
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
}

int maxLength(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    
    for (int i = 0; i < n; ++i) {
        long long prod = 1;       
        long long currentGCD = 0; 
        long long currentLCM = 1; 
    
        for (int j = i; j < n; ++j) {
            prod = (prod * nums[j]) % MOD;
            currentGCD = (j == i) ? nums[j] : gcd(currentGCD, nums[j]);
            currentLCM = lcm(currentLCM, nums[j]);
    
            if (prod == (currentGCD * currentLCM) % MOD) {
                res = max(res, j - i + 1);
            }
        }
    }
    
    return res;
}

int main() {
    init();
    
    cout << maxLength(nums) << endl;

    return 0;
}

// Q1. Maximum Subarray With Equal Products
// Weekly Contest 431: 04/01/2025 - Easy 
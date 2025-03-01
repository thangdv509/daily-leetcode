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

vector<int> applyOperations(vector<int>& nums) {
    for(int i = 0; i+1 < nums.size(); ++i){
        if(nums[i] == nums[i+1]){  
            nums[i] = 2*nums[i]; 
            nums[i+1] = 0;
        }
    }
    int i = 0;
    for(auto n: nums){  
        if(n != 0) nums[i++] = n;
    }
    while(i < nums.size()) nums[i++] = 0;    
    
    return nums;
}

int main() {
    init();

    vector<int> res = applyOperations(nums);

    for(int num : res) cout << num << " ";

    return 0;
}

// 2460. Apply Operations to an Array
// Daily question: 01/03/2025 - Easy
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init(){
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
}


bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0] % 2;

    for(int i = 1; i < n; ++i) {
        int cur = nums[i] % 2;
        if(cur == prev) return false;
        prev = cur;
    }

    return true;
}

int main() {
    init();

    cout << isArraySpecial(nums) << endl;

    return 0;
}

// 3151. Special Array I
// Daily question: 01/02/2025 - Easy
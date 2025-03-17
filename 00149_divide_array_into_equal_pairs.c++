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


bool divideArray(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i+=2)
    {
     if(nums[i]!=nums[i+1])
     {
         return false;
     }
    }
    return true;
}

int main() {
    init();

    cout << divideArray(nums) << endl;

    return 0;
}

// 2206. Divide Array Into Equal Pairs
// Daily question: 17/03/2025 - Easy
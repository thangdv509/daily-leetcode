#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while (ss >> num) nums.push_back(num);
    cin >> k;
}
    
int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); 
    int next_available = -100000;       
    int result = 0;

    for (int num : nums) {
        next_available = max(next_available, num - k);
        if (next_available <= num + k) {
            result++;
            next_available++; 
        }
    }

    return result; 
}

int main () {
    init();

    cout << maxDistinctElements(nums, k) << endl;

    return 0;
}

// 3397. Maximum Number of Distinct Elements After Operations
// Weekly Contest 429: 22/12/2024 - Medium
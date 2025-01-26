#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<unordered_set>
using namespace std;

vector<int> nums;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
    
    cin >> k;
}

int maxFrequency(vector<int>& nums, int k) {
    int totalK = 0;
    for (int num : nums) {
        if (num == k) totalK++;
    }

    unordered_set<int> xVals;
    for (int num : nums) {
        xVals.insert(k - num);
    }

    int maxCount = totalK;

    for (int x : xVals) {
        if (x == 0) {
            maxCount = max(maxCount, totalK);
        } else {
            vector<int> transformed(nums.size(), 0);
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == k - x) transformed[i] = 1;
                else if (nums[i] == k) transformed[i] = -1;
                else transformed[i] = 0;
            }

            int currentMax = 0, maxSoFar = 0;
            for (int t : transformed) {
                currentMax = max(t, currentMax + t);
                maxSoFar = max(maxSoFar, currentMax);
            }

            maxCount = max(maxCount, maxSoFar + totalK);
        }
    }

    return maxCount;
}

int main() {
    init();

    cout << maxFrequency(nums, k) << endl;

    return 0;
}

// 3434. Maximum Frequency After Subarray Operation
// Weekly Contest 434: 26/01/2025 - Medium
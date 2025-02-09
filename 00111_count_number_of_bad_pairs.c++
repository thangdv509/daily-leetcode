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

long long countBadPairs(vector<int>& nums) {
    unordered_map<int, int> freq;
    long long goodPairs = 0, n = nums.size();
            
    for (int i = 0; i < n; i++) {
        int key = nums[i] - i;
        goodPairs += freq[key];
        freq[key]++;
    }
            
    return (n * (n - 1)) / 2 - goodPairs;
}

int main() {
    init();

    cout << countBadPairs(nums) << endl;

    return 0;
}

// 2364. Count Number of Bad Pairs
// Daily question: 09/02/2025 - Medium
#include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<sstream>
using namespace std;

vector<int> nums;
int k;
int multiplier;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while (ss >> num) nums.push_back(num);

    cin >> k >> multiplier;
}

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push({nums[i], i});
    }

    while(k) {
        auto [value, index] = minHeap.top();
        nums[index] = nums[index]*multiplier;
        minHeap.pop();
        minHeap.push({nums[index], index});
        k--;
    }

    return nums;
}

int main() {
    init();

    vector<int> res = getFinalState(nums, k, multiplier);

    for(int num : res) cout << num << " ";

    cout << endl;

    return 0;
}

// 3264. Final Array State After K Multiplication Operations I
// Daily question: 16/12/2024 - Easy
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
    while(ss >> num) nums.push_back(num);

    cin >> k;
}


int minOperations(vector<int>& nums, int k) {
    int res = 0;
    int n = nums.size();
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;

    for(int num : nums) minHeap.push(num);

    while(!minHeap.empty() || n >= 2) {
        long long first = minHeap.top();
        if(first >= k) return res;
        minHeap.pop();

        long long second = minHeap.top(); 
        minHeap.pop();

        long long newNum = 2 * first + second;

        minHeap.push(newNum);
        n -= 2;
        res ++;
    } 

    return -1;
}

int main() {
    init();

    cout << minOperations(nums, k) << endl;

    return 0;
}

// 3066. Minimum Operations to Exceed Threshold Value II
// Daily question: 13/02/2025 - Medium
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;

    while(ss >> num) nums.push_back(num);

    cin >> k;
}

long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> pre(n);

    for(int i = 0; i < n; ++i) {
        pre[i] = nums[i];
        if(i) pre[i] += pre[i-1];
    }

    long long res = -1e18;
    for(int i = 0; i < k; i++) {
        int j = i;
        long long cur = 0;
        while(j + k <= n) {
            cur += pre[j + k - 1] - (j == 0 ? 0 : pre[j-1]);
            res = max(res, cur);
            if(cur < 0) cur = 0;
            j += k;
        }
    }

    return res;
}
 
int main() {
    init();

    cout << maxSubarraySum(nums, k) << endl;

    return 1;
}

// 3381. Maximum Subarray Sum With Length Divisible by K
// Weekly Contest 427: 08/12/2024 - Medium
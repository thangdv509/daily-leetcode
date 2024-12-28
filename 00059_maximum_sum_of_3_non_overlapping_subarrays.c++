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

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> ksum(n-k+1, 0), L(n-3*k+1, -1);
    ksum[0] = accumulate(nums.begin(), nums.begin()+k, 0);
    L[0] = 0;
    int maxKsum = ksum[0];

    for(int i = 1; i < n-k+1; ++i) {
        ksum[i] = ksum[i-1] - nums[i-1] + nums[i+k-1];
        if(i > n-3*k) continue;
        if(maxKsum < ksum[i]) {
            maxKsum = ksum[i];
            L[i] = i;
        }
        else L[i] = L[i-1];
    }

    vector<int> R(n-3*k+1, -1);
    maxKsum = ksum.back();
    R.back() = n-k;

    for(int i = n-k-1; i >= 2*k; --i) {
        if(maxKsum <= ksum[i]) {
            maxKsum = ksum[i];
            R[i-2*k] = i;
        }
        else R[i-2*k] = R[i+1-2*k];
    }

    vector<int> ans(3, -1);
    int max3K = 0;
    
    for(int i = 0; i <= n-3*k; ++i) {
        int sum3K = ksum[L[i] + ksum[i+k] + ksum[R[i]]];
        if(sum3K > max3K) {
            max3K = sum3K;
            ans={L[i], i+k, R[i]};
        }
    }

    return ans;
}

int main() {
    init();

    vector<int> ans = maxSumOfThreeSubarrays(nums, k);

    for(int num : ans) cout << num << " " << endl;

    return 0;
}

// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// Daily question: 28/12/2024 - Hard 
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
long long k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int candy;
    while(ss >> candy) nums.push_back(candy);

    cin >> k;
}

bool canRob(vector<int>& nums, int mid, int k) {
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] <= mid) {
            count++;
            i++;
        }
    }
    return count >= k;
}

int minCapability(vector<int>& nums, int k) {
    int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canRob(nums, mid, k)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    init();

    cout << minCapability(nums, k) << endl;

    return 0;
}

// 2560. House Robber IV
// Daily question: 15/03/2025 - Medium
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
vector<vector<int>> queries;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);

    while(getline(cin, line)) {
        if(line.empty()) break;
        istringstream ss (line);
        vector<int> temp;
        int pos = 0;
        while(ss >> num) {
            temp[pos] = num;
            pos++;
        }
        queries.push_back(temp);
    }
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    auto canMakeZeroArray = [&](int k) {
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            diff[left] += val;
            diff[right + 1] -= val;
        }
        int currVal = 0;
        for (int i = 0; i < n; i++) {
            currVal += diff[i];
            if (currVal < nums[i]) return false;
        }
        return true;
    };
    if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
    int left = 1, right = queries.size();
    if (!canMakeZeroArray(right)) return -1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMakeZeroArray(mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    init();

    cout << minZeroArray(nums, queries) << endl;

    return 0;
}

// 3356. Zero Array Transformation II
// Daily question: 13/03/2025 - Medium
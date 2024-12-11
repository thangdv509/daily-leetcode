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

int maximumBeauty(vector<int>& nums, int k) {
    int freq[100001] = {0};
    int xMax = 0;
    int xMin = 1e6;

    for (int x : nums) {
        freq[x] ++;
        xMax = max(x, xMax);
        xMin = min(x, xMin);
    }

    int cnt = 0, maxCnt = 0;
    for(int l=xMin, r=xMin; r <= xMax; ++r) {
        cnt += freq[r];
        while(r - l > 2*k) {
            cnt -= freq[l];
            l++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main() {
    init();

    cout << maximumBeauty(nums, k) << endl;

    return 0;
}

// 2779. Maximum Beauty of an Array After Applying Operation
// Daily question: 11/12/2024 - Medium

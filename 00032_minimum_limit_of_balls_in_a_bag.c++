#include<bits/stdc++.h>
#include<sstream>
#include<iostream>
using namespace std;

vector<int> nums;
int maxOperations;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }

    cin >> maxOperations;
}

bool canDistribute(const vector<int>& nums, int maxOperations, int maxBalls){
    int accOperations = 0;

    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] <= maxBalls) break;
        accOperations += (nums[i] - 1) / maxBalls; 
        if(accOperations > maxOperations) return false;
    }
    
    return true;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    sort(nums.begin(), nums.end());

    int low = 1;
    int high = nums.back();
    int res = high;

    while(low < high) {
        int mid = low + (high - low) / 2;
        if(canDistribute(nums, maxOperations, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    init();
    cout << minimumSize(nums, maxOperations) << endl;

    return 1;
}

// 1760. Minimum Limit of Balls in a Bag
// Daily question: 07/12/2024 - Medium
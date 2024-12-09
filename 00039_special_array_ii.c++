#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
vector<vector<int> > queries;

void init() {
    string line1;
    getline(cin, line1);
    istringstream ss1(line1); 
    int num;
    while(ss1 >> num) nums.push_back(num);

    int pos = 0;
    string line2;
    vector<int> temp(2, 0);
    getline(cin, line2);
    istringstream ss2(line2);
    while(ss2 >> num) {
        temp[pos] = num;
        if(pos % 2 == 1) queries.push_back(temp);
        pos++;
    }
}

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int> >& queries) {
    int n = nums.size();
    vector<int> prefix(n, 0);

    for(int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1];
        if((nums[i-1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i-1] % 2 != 0 && nums[i] % 2 != 0)) prefix[i]++;
    }

    vector<bool> ans;

    for(auto& q : queries) {
        int left = q[0];
        int right = q[1];
        int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
        ans.push_back(specialCount == 0);
    }

    return ans;
}

int main() {
    init();

    vector<bool> ans = isArraySpecial(nums, queries);

    for(bool res : ans) cout << res << " ";

    return 1;
}

// 3152. Special Array II
// Daily question: 09/12/2024 - Medium
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    while(ss >> num) nums.push_back(num);
}

long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    deque<int> q;

    for(int i = 0; i < n; ++i) {
        if(!q.empty() && nums[i] >= q.back()) {
            bool skip = false;
            while(!q.empty()) {
                int add = q.back();
                q.pop_back();
                if(!skip) {
                    score += add;
                }
                skip = !skip;
            }
            continue;
        }

        q.push_back(nums[i]);
    }

    bool skip = false;
    while (!q.empty()) {
        int add = q.back();
        q.pop_back();
        if (!skip) {
            score += add;
        }
        skip = !skip;
    }

    return score;
}


int main() {
    init();

    cout << findScore(nums) << endl;

    return 0;
}

// 2593. Find Score of an Array After Marking All Elements
// Daily question: 13/12/2024 - Medium